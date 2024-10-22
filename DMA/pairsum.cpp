#include <iostream>
#include <vector>
using namespace std;
int main(){
  vector<int>ans;
  vector<int>n={2,7,11,15};
  int target=9;
  int start=0,end=n.size()-1;
  while(start<end){
    int curr_sum=n[start]+n[end];
    if(curr_sum==target){
      ans.push_back(start);
      ans.push_back(end);
    }
    if(curr_sum<target){
       start++;
    }
    else{
      end--;
    }
  }

  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }

  return 0;
}
