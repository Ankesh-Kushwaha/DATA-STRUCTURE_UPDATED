#include <iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>> &ans, vector<int> output, vector<int> &arr, int idx){
  //base case
  if(idx >= arr.size()){
    ans.push_back(output);
    return;
  }

  //element excluded
  solve(ans, output, arr, idx+1);

  //element included
  output.push_back(arr[idx]);
  solve(ans, output, arr, idx+1);
}

void print(vector<vector<int>> &ans){
  for(int i = 0; i < ans.size(); i++){
    for(int j = 0; j < ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  vector<int> arr;
  for(int i = 1; i <=5; i++){
     arr.push_back(i);
  }

  vector<vector<int>> ans;
  vector<int> output;
  int idx = 0;
  solve(ans, output, arr, idx);
  print(ans);

  return 0;
}
