#include <iostream>
using namespace std;

int main(){
  int n;
  cout<<"enter the size of array:"<<endl;
  cin>>n;
  //allocating memory dynamically;
  int *arr=new int[n];
  int x=1;
  for(int i=0;i<n;i++){
    arr[i]=x;
    cout<<arr[i]<<" ";
    x++;
  }
  cout<<endl;
  return 0;
}