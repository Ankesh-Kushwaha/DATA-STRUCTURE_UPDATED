#include<iostream>
#include <vector>
using namespace std;

int update(int num,vector<int> &setBit,int op){
  for (int i = 0; i < 32;i++){
       if((num>>i)&1){
         setBit[i] += op;
       }
  }
}

int getNumberFromBinary(vector<int> &setBit){
  int num = 0;
  for (int i = 0; i < 32;i++){
     if(setBit[i]>0){
       num |= 1 << i;
     }
  }
  return num;
}

int length(vector<int> nums,int k){
  int n = nums.size();
  int result = INT32_MAX;
  vector<int> setBit(32, 0);

  int i = 0;
  int j = 0;
   while(j<n){
     update(nums[j], setBit, 1); // adding current value to the window;

     while (i <= j && getNumberFromBinary(setBit)>=k){
       result = min(result, j - i + 1);
       update(nums[i], setBit, -1);   //removing current value from the window;
       i++;
     }
     j++;
   }
   return result == INT32_MAX ? -1 : result;
}

int main(){
  vector<int> nums = {3, 3, 3, 2, 1, 5, 5};
  int k = 6;
  cout << "required smallest subArray length is :" << length(nums, k) << endl;
  return 0;
}