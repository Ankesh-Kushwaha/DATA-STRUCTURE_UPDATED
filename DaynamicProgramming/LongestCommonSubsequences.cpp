#include<iostream>
#include<vector>
#include<string>
using namespace std;

// LCS using recursion
int LCSRec(string s1,string s2){
  //Base case
   
  if(s1.length()==0 || s2.length()==0){
        return 0;
  } 
   
  int n=s1.length();
  int m=s2.length();
  
  if(s1[n-1]==s2[m-1]){
     return 1 + LCSRec(s1.substr(0,n-1),s2.substr(0,m-1));
  }
  else{
    int ans1=LCSRec(s1.substr(0,n-1),s2);
    int ans2=LCSRec(s1,s2.substr(0,m-1));
    return max(ans1,ans2);
  }
}

//Approach 2---> Memoization
int LCSRec2(string s1,string s2){
  //Base case
   
  if(s1.length()==0 || s2.length()==0){
        return 0;
  } 
   
  int n=s1.length();
  int m=s2.length();
  //defining storage
  vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
  
  if(dp[n][m]!=-1){
      return dp[n][m];
  }
  
  if(s1[n-1]==s2[m-1]){
     dp[n][m]= 1 + LCSRec(s1.substr(0,n-1),s2.substr(0,m-1));
  }
  else{
    int ans1=LCSRec(s1.substr(0,n-1),s2);
    int ans2=LCSRec(s1,s2.substr(0,m-1));
    dp[n][m]= max(ans1,ans2);
  }

  //printing memoization array
  cout<<"Memoization array"<<endl;
  for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }

  return dp[n][m];
}

// Approach 3--> Tabulation 

int LCSRec3( string s1,string s2){
  int n=s1.length();
  int m=s2.length();
  vector<vector<int>> dp(n+1,vector<int> (m+1,0));

  for(int i=1;i<n+1;i++){
      for(int j=1;j<m+1;j++){
          if(s1[i-1]==s2[j-1]){
              dp[i][j]=dp[i-1][j-1]+1;
          }
          else{
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
      }
  }

  for(int i=0;i<n+1;i++){
    for(int j=0;j<m+1;j++){
       cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }

  return dp[n][m];
}

int main(){
  string s1="abcdge";
  string s2="abedg";
  
  cout<<LCSRec3(s1,s2)<<endl;
  return 0;
}