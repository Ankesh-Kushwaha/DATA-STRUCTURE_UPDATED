#include <iostream>
using namespace std;

void bubblesort(int*arr,int n){
  for(int i=0;i<n-1;i++){
  bool isSwap=false;
    for(int j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
       swap(arr[j],arr[j+1]);
       isSwap=true;
    }
  }

  if(!isSwap){
    return; //array is already sorted
  }
}
}

void print_array(int*arr,int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}


int main(){
  int arr[]={9,8,7,6,5,4,3,2,1};
  int n=sizeof(arr)/sizeof(int);
  bubblesort(arr,n);
  print_array(arr,n);
  return 0;
}