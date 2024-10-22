#include <iostream>
using namespace std;
int main(){
  //input in array;
  int arr[100];
  int n;
  //int n=sizeof(arr)/sizeof(int);
  cout<<"enter the size of array:"<<endl;
  cin>>n;
  cout<<"enter the element in array:"<<endl;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

//output in array;
cout<<"output array"<<endl;
for(int i=0;i<n;i++){
  cout<<arr[i]<<" ";
}

  return 0;
}