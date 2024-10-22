#include <iostream>
#include<vector>
using namespace std;
int threeSumClosest(vector<int>nums, int target,int n) {
        //sort(nums.begin(),nums.end());
        int diff=INT32_MAX;
        int closest_sum=0;
        for(int i=0;i<n-2;i++){
            int start=i+1;
            int end=n;
            while(start<end){
                int curr_sum=nums[i]+nums[start]+nums[end];
                if(curr_sum==target) return curr_sum;
                if(abs(curr_sum-target)<diff){
                    diff=abs(curr_sum-target);
                    closest_sum=curr_sum;
                }
                else if(curr_sum<target){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        return closest_sum;
    }
int main(){
  return 0;
}