#include <iostream>
using namespace std;

void takeinput(int arr[],int n){
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
}

int find_greatest(int arr[],int n){
     int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
          max=arr[i];
        }
    }
    return max;
}

int find_smallest(int arr[],int n){
      int min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<min){
          min=arr[i];
        }
    }
    return min;
}


int main(){
   int arr[100];
  int n;
  cout<<"enter the size of array:"<<endl;
  cin>>n;
  cout<<"enter the element in array:"<<endl;
  takeinput(arr,n);
 
 int ans=find_greatest(arr,n);
 int ans2=find_smallest(arr,n);
 cout<<"greatest element in array is :"<<ans<<endl;
  cout<<"smallest element in array is :"<<ans2<<endl;
  return 0;
}
