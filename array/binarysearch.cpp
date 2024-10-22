#include <iostream>
using namespace std;

int binary_search(int arr[],int target,int n){
  int start=0,end=n-1;
  while(start<=end){
    int mid=start+(end-start)/2;
    if(arr[mid]==target){
      return mid;
    }
    if(arr[mid]<=target){
      start=mid+1;
    }
    else{
      end=mid-1;
    }
  }
  return -1;
}

void takeinput(int arr[],int n){
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
}
int main(){
  int n,key;
  cout<<"enter the length of array:"<<endl;
  cin>>n;
  int arr[n];
  cout<<"enter the element of array:"<<endl;
  takeinput(arr,n);
  cout<<"enter the key to search:"<<endl;
  cin>>key;
  int ans=binary_search(arr,key,n);
  cout<<"the key is present at the index:"<<ans<<endl;

  return 0;
}