#include <iostream>
using namespace std;
int last_ocurr(int *arr,int n,int i,int target){
   //base case;
   if(i==0){
    return -1;
   }

   if(arr[i]==target){
    return i;
   }

   return last_ocurr(arr,n,i-1,target);
}

int first_ocurr(int*arr,int n,int i,int target){
  //base case;
  if(i==n-1){
    return -1;
  }


  if(arr[i]==target){
    return i;
  }
  
  return first_ocurr(arr,n,i+1,target);
}
int main(){
  int arr[6]={1,2,3,3,3,4};
  int ans=last_ocurr(arr,6,5,3);
   cout<<ans<<endl;
  return 0;
}