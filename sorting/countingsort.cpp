#include <iostream>
using namespace std;

void print_array(int*arr,int n){
   for(int i=0;i<n;i++){
     cout<<arr[i]<<" ";
   }
   cout<<endl;
}

void counting_sort(int *arr,int n){
    //making of frequency array &finding the range of element;
    int freq[1000]={0};
    int min_range=INT32_MAX;
    int max_range=INT32_MIN;
    for(int i=0;i<n;i++){
         freq[arr[i]]++;
         min_range=min(min_range,arr[i]);
         max_range=max(max_range,arr[i]);
    }

    //moddifying our original array;
   
    for(int i=min_range,j=0;i<=max_range;i++){
      while(freq[i]>0){
        arr[j++]=i;
        freq[i]--;
      }
    }

    print_array(arr,n);
}

void taking_input(int *arr,int n){
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
    counting_sort(arr,n);
}

int main(){
  int n;
  cout<<"enter the size of array:"<<endl;
  cin>>n;
  int arr[n];
  cout<<"enter the element in array to sort:"<<endl;
  taking_input(arr,n);

  return 0;
}
