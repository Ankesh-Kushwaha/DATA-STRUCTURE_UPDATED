#include<iostream>
#include<vector>
#include<string>
using namespace std;
int LCSRec(string str1,string str2){
      //base case
      if(str1.length()==0 || str2.length()==0){
        return 0;
      }
      
      int n=str1.length();
      int m=str2.length();

      if(str1[n-1]==str2[m-1]){
          return 1+LCSRec(str1.substr(0,n-1),str2.substr(0,n-1));
      }
      else{
        int ans1=LCSRec(str1.substr(0,n-1),str2);
        int ans2=LCSRec(str1,str2.substr(0,m-1));
        return max(ans1,ans2);
      }
}

//approch 2 by memoization
int LCSMemo(string str1,string str2,vector<vector<int>> &dp){
    //base case
    if(str1.length()==0 || str2.length()==0){
       return 0;
    }
    int n=str1.length();
    int m=str2.length();
   
    if(dp[n][m]!=0){
        return dp[n][m];
    }
    
    if(str1[n-1]==str2[m-1]){
        dp[n][m]=1+LCSMemo(str1.substr(0,n-1),str2.substr(0,m-1),dp);
    }
    else{
      int ans1=LCSMemo(str1.substr(0,n-1),str2,dp);
      int ans2=LCSMemo(str1,str2.substr(0,m-1),dp);
      dp[n][m]=max(ans1,ans2);
    }
    return dp[n][m];
}

//approach 3 -> By Tabulation

int LCSTabu(string str1,string str2){
       int n=str1.size();
       int m=str2.size();
       vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       for(int i=1;i<n+1;i++){
         for(int j=1;j<m+1;j++){
             if(str1[i-1]==str2[j-1]){
                  dp[i][j]=1+dp[i-1][j-1];
             }
             else{
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
             }
         }
       }

    cout<<"printing Tabulation Array:"<<endl;
    for(int i=0;i<n+1;i++){
      for(int j=0;j<m+1;j++){
           cout<<dp[i][j]<<" ";
      }
      cout<<endl;
    }

  return dp[n][m];
}

int main(){
   string str1="abcdge";
   string str2="abedg";
    vector<vector<int>> dp(str1.length()+1,vector<int> (str2.length()+1,0));
   cout<<LCSMemo(str1,str2,dp)<<endl;
     cout<<"Memoization array"<<endl;
  for(int i=0;i<str1.size()+1;i++){
    for(int j=0;j<str2.size()+1;j++){
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"result in Tabulation case:"<<LCSTabu(str1,str2);
  
   return 0;
}