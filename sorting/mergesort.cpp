#include <iostream>
#include <vector>
using namespace std;

void merge(int *arr,int si,int ei,int mid){
   vector<int>temp;
   int i=si;
   int j=mid+1;
   //merging array in sorted form
   while(i<=mid && j<=ei){
       if(arr[i]<=arr[j]){
         temp.push_back(arr[i++]);
       }
       else{
        temp.push_back(arr[j++]);
       }
   }

   //merging the left outpart of the arrays;
   while(i<=mid){
      temp.push_back(arr[i++]);
   }

   while(j<=ei){
      temp.push_back(arr[j++]);
   }

   //copying the temp array to original array;
   for(int idx=si ,x=0;idx<=ei;idx++){
      arr[idx]=temp[x++];
   }

}

void merge_sort(int *arr,int si,int ei){

  //base case;
  if(si>=ei){
    return ;
  }

  int mid=si+(ei-si)/2;
  
  //dividing array;
  merge_sort(arr,si,mid); //left part;
  merge_sort(arr,mid+1,ei); //right part;
  
  //conqueroning the divided array;
  merge(arr,si,ei,mid);
}

//printing array
void print_array(int *arr,int n){
  cout<<"the required sorted array is:"<<endl;
   for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
   }
   cout<<endl;
}

int main(){
  int n;
  cout<<"enter the size of array:"<<endl;
  cin>>n;
  int arr[n];
  cout<<"enter the element in array:"<<endl;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  merge_sort(arr,0,n);
  print_array(arr,n);
  return 0;
}
