#include<iostream>
#include<vector>
using namespace std;
// tabulation approarch;
int minimumPathSum(vector<vector<int>> grid){
  int m = grid.size();
  int n = grid[0].size();
  vector<vector<int>> dp(m, vector<int>(n, 0));

  for (int i = 0; i < m;i++){
    for (int j = 0; j < n;j++){
          if(i==0 && j==0){
            dp[i][j] = grid[0][0]; // initialisation;
          }
          else{
            int up = (i > 0) ? grid[i][j] + dp[i - 1][j] : INT32_MAX;
            int right = (j > 0) ? grid[i][j] + dp[i][j - 1] : INT32_MAX;
            dp[i][j] = min(up, right);
          }
    }
  }

  for (int i = 0; i < m;i++){
    for (int j = 0; j < n;j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

    return dp[m - 1][n - 1];
}
int main(){
  vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << minimumPathSum(grid) << endl;
  return 0;
}