#include <iostream>
using namespace std;
void maxSubarraySum1(int *arr,int n){
  int maxsum=INT_FAST32_MIN; //brute force approach;
    for(int start=0;start<n;start++){
    for(int end=start;end<n;end++){
      int sum=0; //time complexity O(n^3);
      for(int i=start;i<=end;i++){
        sum+=arr[i];
        maxsum=max(maxsum,sum);
      }
       cout<<sum<<","; 
    }
    cout<<endl;
  }
  cout<<"maximum subarray sum:=";
  cout<<maxsum<<endl;
}

//some optimised;
void maxSubarraySum2(int *arr,int n){
  int max_sum=INT32_MIN;
  for(int i=0;i<n;i++){ //time complexity =O(n^2);
    int curr_sum=0;
    for(int j=i;j<n;j++){
      curr_sum+=arr[j];
      max_sum=max(max_sum,curr_sum);
    }
    cout<<curr_sum<<",";
  }
  cout<<endl;
  cout<<"maximum sum subarray is:"<<max_sum<<endl;
}

int main(){
  int arr[6]={2,-3,6,-5,4,2};
  //maxSubarraySum1(arr,6);
  maxSubarraySum2(arr,6);
 
  return 0;
}
