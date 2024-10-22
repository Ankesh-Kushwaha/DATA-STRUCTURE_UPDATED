#include <iostream>
using namespace std;
int search(int *arr,int si,int ei,int target){
     //base case
     if(si>ei){
      return -1;
     }

   int mid=si+(ei-si)/2;
   if(arr[mid]==target){
    return mid;
   }

   if(arr[si]<=arr[mid]){//L1;
       if(arr[si]<=target && target<=arr[mid]){
        //left half;
          return search(arr,si,mid-1,target);
       }
       else{
        //right half
        return  search(arr,mid+1,ei,target);
       }
   }
   else{//l2
      if(arr[mid]<=target && target<=arr[ei]){
         return  search(arr,mid+1,ei,target);
      }
      else{
          return search(arr,si,mid-1,target);
      }
   }
}
int main(){
   int n,target;
    cout << "Enter the size of array:" << endl;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter the elements in the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"enter the value of target to search:"<<endl;
    cin>>target;

  cout<<search(arr,0,n-1,target)<<endl;
  return 0;
}