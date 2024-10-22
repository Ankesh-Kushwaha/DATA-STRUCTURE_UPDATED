#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int longestIncresingSub(vector<int> arr){
  set<int> s(arr.begin(),arr.end()); //create to store unique increasing subsiquences
  vector<int> arr2(s.begin(),s.end()); //create a second array to sort
  sort(arr2.begin(),arr2.end());

  int n=arr.size();
  int m=arr2.size();
  vector<vector<int>>dp(n+1,vector<int> (m+1,0));

  for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){
      if(arr[i-1]==arr2[j-1]){
         dp[i][j]=1+dp[i-1][j-1];
      }
      else{
         dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
   
   //printing the dp array
    for(int i=0;i<n+1;i++){
      for(int j=0;j<m+1;j++){
         cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }

   return dp[n][m];
}
int main(){
  vector<int> arr={50,3,10,7,40,80};
  cout<<"longest increasing sequences is:"<<longestIncresingSub(arr)<<endl;
  return 0;
}