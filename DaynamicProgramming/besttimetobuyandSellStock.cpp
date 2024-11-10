#include<iostream>
#include<vector>
using namespace std;

//approach 1.using recursion
int maxProfit(int idx,int canBuy,vector<int> prices,int fee){
   if(idx==prices.size()){  //base case
     return 0;
   }

   int buy = INT32_MIN;
   int sell = INT32_MIN;
   if(canBuy){
     buy =-prices[idx] + maxProfit(idx + 1, !canBuy, prices, fee);
   }
   else{
     sell = prices[idx]-fee + maxProfit(idx + 1, !canBuy, prices, fee);
   }
   int move_on = maxProfit(idx + 1, canBuy, prices, fee);
   return max(buy, max(sell, move_on));
}


// Approach 2. using memoization;
int maxProfitMemo(int idx, int canBuy, vector<int> prices, int fee,vector<vector<int>> &dp)
{
  if (idx == prices.size())
  { // base case
    return 0;
  }

  int buy = INT32_MIN;
  int sell = INT32_MIN;

  if(dp[idx][canBuy]!=-1){
    return dp[idx][canBuy];
  }

  if (canBuy)
  {
    buy = -prices[idx] + maxProfitMemo(idx + 1, !canBuy, prices, fee,dp);
  }
  else
  {
    sell = prices[idx] - fee + maxProfitMemo(idx + 1, !canBuy, prices, fee,dp);
  }
  int move_on = maxProfitMemo(idx + 1, canBuy, prices, fee,dp);
  return  dp[idx][canBuy] = max(buy, max(sell, move_on));
}
// Approach 3. Tabulation;



int main(){
  vector<int> prices = {1, 3, 2, 8, 4, 9};
  int fee = 2;
  int n = prices.size();
  vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    cout << "required Max profit:" << maxProfitMemo(0, 1, prices, fee, dp) << endl;

    for (int i = 0; i < dp.size(); i++)
    {
      for (int j = 0; j < 2; j++)
      {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
  return 0;
}