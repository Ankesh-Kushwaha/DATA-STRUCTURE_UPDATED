#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void majorityele(vector<int> nums){
 unordered_map<int,int> m;
 for(int i=0;i<nums.size();i++){
   if(m.count(nums[i])){
    m[nums[i]]++;
   }
   else{
    m[nums[i]]=1;
   }
 }

 for(pair<int,int> freq:m){
  if(freq.second > nums.size()/3){
    cout<<freq.first<<" ";
  }
 }
 cout<<endl;
}

int main() {
    vector<int> element = {1, 3, 2, 5, 1, 3, 1, 5, 1};
    majorityele(element);
    return 0;
}
