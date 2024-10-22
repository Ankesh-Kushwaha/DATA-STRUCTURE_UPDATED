#include<iostream>
#include<vector>
using namespace std;
//approach 1 using recursion
int KnapSack(vector<int> val,vector<int> wt,int W,int n){
    int itemWt=wt[n-1];
    int itemProfit=val[n-1];
    //base case
   if(n==0 || W==0){
    return 0;
   }
   
   //include
   if(itemWt<=W){
      //include
      int ans1=KnapSack(val,wt,W-itemWt,n-1)+itemProfit;
      //exclude
      int ans2=KnapSack(val,wt,W,n-1);
      return max(ans1,ans2);
   }
   else{
         //exclude
      return KnapSack(val,wt,W,n-1);
   }

}

//2.approach using memoization
int KnapSack2(vector<int> val,vector<int> wt,int W,int n,vector<vector<int>> &dp){
    int itemWt=wt[n-1];
    int itemProfit=val[n-1];
    //base case
   if(n==0 || W==0){
    return 0;
   }
   
   if(dp[n][W]!=-1){
    return dp[n][W];
   }
   //include
   if(itemWt<=W){
      //include
      int ans1=KnapSack2(val,wt,W-itemWt,n-1,dp)+itemProfit;
      //exclude
      int ans2=KnapSack2(val,wt,W,n-1,dp);
      dp[n][W]= max(ans1,ans2);
   }
   else{
         //exclude
      dp[n][W]= KnapSack2(val,wt,W,n-1,dp);
   }
  return dp[n][W];
}

int knapSackTabu(vector<int> val,vector<int> wt, int W,int n){
   vector<vector<int>> dp(n+1,vector<int> (W+1,0));
   
   for(int i=1;i<n+1;i++){
      for(int j=1;j<W+1;j++){
           int itemVal=val[i-1];
           int itemWt=wt[i-1];
           if(itemWt<=j){ //item can be included
             dp[i][j]=max(itemVal+dp[i-1][j-itemWt],dp[i-1][j]);
           }
           else{ //item can not be included
             dp[i][j]=dp[i-1][j];
           }
      }
   }
   cout<<endl;
   cout<<endl;
   for(int i=0;i<n+1;i++){
      for(int j=0;j<W+1;j++){
         cout<<dp[i][j]<<" ";
      }
      cout<<endl;
   }

  return dp[n][W];
}

int main(){
vector<int> val={15,14,10,45,30};
vector<int> wt={2,5,1,3,4};
int W=7;
int n=5;
vector<vector<int>> dp(n+1,vector<int> (W+1,-1));
int maxProfit=KnapSack2(val,wt,W,n,dp);
cout<<"the maximum profit is:"<<maxProfit<<endl;

//printing the dp array
cout<<"reuired DP array is:"<<endl;
for(int i=0;i<n+1;i++){
  for(int j=0;j<W+1;j++){
    cout<<dp[i][j]<<" ";
  }
  cout<<endl;
}

cout<<"maximum profit:"<<knapSackTabu(val,wt,W,n)<<endl;

  return 0;
}