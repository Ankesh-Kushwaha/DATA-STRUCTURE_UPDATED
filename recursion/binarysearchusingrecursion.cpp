#include <iostream>
using namespace std;

int binary_search(int *arr,int start,int end,int key){
  if(start>end){
    return -1;
  }

  int mid=start+(end-start)/2;
  //base case
  if(arr[mid]==key){
    return mid;
  }

  if(arr[mid]<key){ //right half
    binary_search(arr,mid+1,end,key);
  }
  else{ //left half
     binary_search(arr,start,mid-1,key);
  }
  
}

int main(){
  int arr[7]={1,2,3,4,5,6,7};
  cout<<binary_search(arr,0,6,5)<<endl;
  return 0;
}