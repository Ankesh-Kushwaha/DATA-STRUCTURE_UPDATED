#include <iostream>
using namespace std;
void kadanesalgo(int *arr,int n){
    int max_sum=INT_FAST32_MIN;
    int curr_sum=0;  //time complexity=> O(n);
    for(int i=0;i<n;i++){
      curr_sum+=arr[i];
      if(curr_sum<0){
        curr_sum=0;
      }
      max_sum=max(max_sum,curr_sum);
    }

    cout<<max_sum<<endl;
}

int main(){
 int arr[]={2,-3,6,-5,4,2};
 int n=sizeof(arr)/sizeof(int);
 kadanesalgo(arr,n);
  return 0;
}