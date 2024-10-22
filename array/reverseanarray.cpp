#include <iostream>
using namespace std;

void takeinput(int arr[],int n){
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
}

void reverse_array(int *arr,int *copy_array,int n){
  for(int i=0;i<n;i++){
    int j=n-i-1;
    copy_array[i]=arr[j];
  }

  for(int i=0;i<n;i++){
    arr[i]=copy_array[i];
  }

}

//two pointer approach;
void reverse_array2(int *arr,int n){
  int start=0;
  int end=n-1;
  
  while(start<=end){
    swap(arr[start],arr[end]);
    start++;
    end--;
  }
}

void print_array(int*arr,int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}

int main(){
  int n;
  cout<<"enter the size of array:"<<endl;
  cin>>n;
  int arr[n];
  int copy_array[n];
  cout<<"enter the size of array:"<<endl;
  takeinput(arr,n);
  reverse_array2(arr,n);
  cout<<"reverse array is :"<<endl;
  print_array(arr,n);
  return 0;
}