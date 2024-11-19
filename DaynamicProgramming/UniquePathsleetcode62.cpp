#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int row,int col,int m,int n,vector<vector<int>> &dp){
  //base case
  if(row==m-1 && col==n-1){
    return 1;
  }

  if(row>=m || col>=n){
    return 0;
  }
  
  if(dp[row][col]!=-1){
    return dp[row][col];
  }

  return dp[row][col] = uniquePaths(row + 1, col, m, n, dp) + uniquePaths(row, col + 1, m, n, dp);
}

int uniquePathsTabu(int m,int n){
  vector<vector<int>> dp(m, vector<int>(n, 0));

  for (int i = 0; i < m;i++){
    for (int j = 0; j < n;j++){
         if(i==0 && j==0){
           dp[i][j] = 1; // initialise the base condition;
           continue;
         }
        else{
          int up = (i > 0) ? dp[i - 1][j] : 0;
          int left = (j > 0) ? dp[i][j - 1] : 0;
          dp[i][j] = up + left;
        }
    }
  }

  for (int i = 0; i < m;i++){
    for (int j = 0; j < n;j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  return dp[m-1][n-1];
}

int main(){
  int m = 3;
  int n = 7;
  vector<vector<int>> dp(m, vector<int>(n, -1));
  cout << uniquePathsTabu(m,n) << endl;

    return 0;
}