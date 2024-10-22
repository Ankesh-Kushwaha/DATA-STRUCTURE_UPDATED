#include <iostream>
using namespace std;
void printarr(int *arr,int n){
   for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
}

void selection_sort(int *arr,int n){
      for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
          if(arr[j]<arr[minindex]){
            minindex=j;
          }
        }
        swap(arr[minindex],arr[i]);
      }

      printarr(arr,n);
}
int main(){
  int arr[]={9,8,7,4,5,6,1,2,3,0};
 int n=sizeof(arr)/sizeof(int);
 selection_sort(arr,n);
  return 0;
}