#include <iostream>
using namespace std;

void trap(int *height,int n){
  //total time complexity=>O(n);
  int leftMax[10000];
  leftMax[0]=height[0];
  int rightMax[10000];
  rightMax[n-1]=height[n-1];

//calculating the left max;
  for(int i=1;i<n;i++){
    leftMax[i]=max(leftMax[i-1],height[i-1]);
  }
  
//calculating the right max;
  for(int i=n-2;i>=0;i--){
    rightMax[i]=max(rightMax[i+1],height[i+1]);
  }

  int waterTrapped=0;
  for(int i=0;i<n;i++){
    int curr_water=min(leftMax[i],rightMax[i])-height[i];
    if(curr_water>0){
      waterTrapped+=curr_water;
    }
  }
  cout<<"the maximum water trapped is :"<<waterTrapped<<endl;
}


int main(){
  int height[]={4,2,0,6,3,2,5};
  int n=sizeof(height)/sizeof(int);
  trap(height,n);
  return 0;
}