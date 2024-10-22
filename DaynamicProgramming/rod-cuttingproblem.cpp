#include<iostream>
#include<vector>
using namespace std;

int main(){
vector<int> price={1,5,8,9,10,17,17,20};
vector<int> length={1,2,3,4,5,6,7,8};
int rodLength=8;
vector<vector<int>> dp(length.size()+1,vector<int>(rodLength,0));

for(int i=1;i<length.size()+1;i++){
  for(int j=1;j<rodLength+1;j++){
       if(length[i-1]<=j){
           dp[i][j]=max(dp[i][j-length[i-1]] +price[i-1] ,dp[i-1][j]);
       }
       else{
          dp[i][j]=dp[i-1][j];
       }
  }
}

cout<<"max price :"<<dp[length.size()][rodLength];
  return 0;
}