#include<iostream>
#include<vector>
#include<string>
using namespace std;

int editDistance(string str1,string str2){
    int n=str1.length();
    int m=str2.length();

    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    //initialisation
    for(int i=0;i<n+1;i++){
       dp[i][0]=i;
    }

    for(int j=0;j<m+1;j++){
      dp[0][j]=j;
    }

    for(int i=1;i<n+1;i++){
      for(int j=1;j<m+1;j++){
           if(str1[i-1]==str2[j-1]){
              dp[i][j]= 0 + dp[i-1][j-1];
           }
           else{
              dp[i][j]=1 + min(dp[i][j-1] , min(dp[i-1][j] , dp[i-1][j-1]));
           }
      }
    }

    return dp[n][m];
}

int main(){
 string str1="horse";
 string str2="ros";
 
 cout<<"no of operations it take to convert str1 to str2 is: "<<editDistance(str1,str2)<<endl;

  return 0;
}