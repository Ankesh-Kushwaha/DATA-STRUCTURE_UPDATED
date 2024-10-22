#include<iostream>
#include<vector>
using namespace std;
int noOfWays(int n){
  if(n==0 || n==1){ //recursive approach
    return 1;       //time complexity=O(n);
  }
  return noOfWays(n-1)+noOfWays(n-2);
}

//memoization
int nWaysMemo(int n){
   vector<int> dp(n+1,-1);
   if(n==1 || n==0){
    return 1;
   }

   if(dp[n]!=-1){
    return dp[n];
   }

   dp[n]=nWaysMemo(n-1)+nWaysMemo(n-2);
   return dp[n];
}

int nWaysTab(int n){
  vector<int> dp(n+1,0);
  dp[0]=1;
  dp[1]=1;

  for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
  }
  return dp[n];
}

int main(){
  int n=6;
  cout<<nWaysTab(n)<<endl;
  return 0;
}