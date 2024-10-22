#include <iostream>
using namespace std;

void print_arr(int *arr,int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void insertion_sort(int *arr,int n){
  for(int i=1;i<n;i++){
    int curr=arr[i];
    int prev=i-1;
    while(prev>=0 && arr[prev]>curr){
      swap(arr[prev],arr[prev+1]);
      prev--;
    }
    arr[prev+1]=curr;
  }

  print_arr(arr,n);
}
int main(){
  int arr[]={9,8,7,4,5,6,3,2,1,0};
  int n=sizeof(arr)/sizeof(int);
  insertion_sort(arr,n);
  return 0;
}