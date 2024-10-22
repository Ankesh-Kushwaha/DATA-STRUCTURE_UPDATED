#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int largestSubarray(vector<int> arr){
  unordered_map<int,int> sumIdx;//key->sum ,value-> idx
  int sum=0;
  int length=0;

  for(int j=0;j<arr.size();j++){
     sum+=arr[j];

     if(sumIdx.count(sum)){
       int currlen=j-sumIdx[sum];//j-idx
       length=max(length,currlen);
     }else{
      sumIdx[sum]=j;
     }
  }
  return length;
}
int main(){
vector<int> arr={15,-2,2,-8,1,7,10};
cout<<"required max length of array with sum 0: "<<largestSubarray(arr)<<endl;
  return 0;
}