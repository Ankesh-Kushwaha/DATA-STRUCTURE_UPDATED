#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FairsPairs(vector<int> nums,int lower,int upper){
  sort(nums.begin(), nums.end());
  int result = 0;
  for (int i = 0; i<nums.size();i++){
    int idx = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin(); // it gives the first idx value whose value is  less than lower  bound;
    int x = idx - 1 - i;

    int idy = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin(); // it gives the first idx value whose value is  less than upper  bound;
    int y = idy - 1 - i;
    result += (y - x);
  }
  return result;
}
int main(){
  vector<int> nums = {1,7,9,2,5};
  int lower = 11;
  int upper = 11;
  cout << FairsPairs(nums, lower, upper) << endl;
  return 0;
}