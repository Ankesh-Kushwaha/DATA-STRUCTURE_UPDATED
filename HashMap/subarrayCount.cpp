#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarrayCount(vector<int> arr,int k){
  unordered_map<int,int> map;
  map[0]=1;
  int sum=0;
  int ans=0;

  for(int i=0;i<arr.size();i++){
     sum+=arr[i];
     if(map.count(sum-k)){
      ans+=map[sum-k];
     }

     if(map.count(sum)){
      map[sum]++;
     }
     else{
      map[sum]=1;
     }
  }
  return ans;
}
int main(){
vector<int> arr={10,2,-2,-20,10};
int k=-10;  

cout<<"required subarray count is : "<<subarrayCount(arr,k)<<endl;
  return 0;
}