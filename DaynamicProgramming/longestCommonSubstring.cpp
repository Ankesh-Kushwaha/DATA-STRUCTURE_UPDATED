#include<iostream>
#include<string>
#include<vector>
using namespace std;

int longestSubstr(string str1,string str2){
    int n=str1.length();
    int m=str2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    int ans=0;
    for(int i=1;i<n+1;i++){
      for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                 ans=max(ans,dp[i][j]);
            }
            else{
              dp[i][j]=0;
            }
      }
    }

    for(int i=0;i<n+1;i++){
      for(int j=0;j<m+1;j++){
        cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }

  return ans;
}

int main(){
   string str1="abcde";
   string str2="abgce";
   cout<<longestSubstr(str1,str2)<<endl;
  return 0;
}