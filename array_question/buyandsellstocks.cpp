#include <iostream>
using namespace std;
void maxprofit(int *prices,int n){
  int bestBuy[100000];
  bestBuy[0]=INT32_MAX;
  for(int i=1;i<n;i++){
    bestBuy[i]=min(bestBuy[i-1],prices[i-1]);
  }
  //time complexity =O[n+n]=>O[2n]=>O[n];
  int maxProfit=0;
  for(int i=0;i<n;i++){
    int curr_profit=prices[i]-bestBuy[i];
    maxProfit=max(maxProfit,curr_profit);
  }

  cout<<"maximum profit is :"<<maxProfit<<endl;
}

int main(){
  int prices[6]={7,1,5,3,6,4};
  int n=sizeof(prices)/sizeof(int);

  maxprofit(prices,n);
  return 0;
}
