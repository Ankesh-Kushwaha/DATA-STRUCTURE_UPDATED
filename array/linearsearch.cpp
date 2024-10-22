#include <iostream>
using namespace std;
int linear_search(int *arr,int n,int key){
  for(int i=0;i<n;i++){
    if(arr[i]==key){
      return i;
    }
  }
  return -1;
}

int main(){
  int n,key;
  cout<<"enter the size of array:"<<endl;
  cin>>n;
  int arr[n];
  cout<<"enter the element in array"<<endl;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

cout<<"enter the key to search:"<<endl;
cin>>key;
  int ans= linear_search(arr,n,key);
  cout<<"index of the key is:"<<ans<<endl;
  return 0;
}