#include<iostream>
#include<vector>
using namespace std;

// recursive approach;
int Catlan(int n,vector<int> &dp){
    //base case
    if(n==0 || n==1){
      return 1;
    }

    if(dp[n]!=-1){
      return dp[n];
    }
    int temp = 0;
    for (int i = 0; i < n;i++){
      temp += Catlan(i,dp) * Catlan(n - i - 1,dp);
    }
    return dp[n]=temp;
}

//tabulation
int CatlanTab(int n){
  vector<int> dp(n + 1, 0);
  dp[0] = dp[1] = 1;

  for (int i = 2; i <=n; i++){
    for (int j = 0; j < i;j++){
      dp[i] +=(dp[j] * dp[i - j - 1]);
    }
  }
  return dp[n];
}

int main(){
  int n = 10;
  vector<int> dp(n + 1, -1);
  for (int i = 0; i <=n;i++){
    cout << CatlanTab(i)<< " ";
  }
    return 0;
}