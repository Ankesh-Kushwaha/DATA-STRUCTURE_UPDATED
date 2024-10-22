#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool compare(pair<double,int> p1 ,pair<double,int> p2){
   return p1.first> p2.first;
}

int Fractional_Knapsack(vector<int> value, vector<int> wt,int W){
    int n=value.size();
    vector<pair<double,int>> ratio(n,make_pair(0.0,0)); // (ratio,idx) making pair to store ratio and its index;
    //calculating the ratio of each index;
    for(int i=0;i<n;i++){
        double r=value[i]/(double)wt[i];
        ratio[i]=make_pair(r,i);
    }

    //sorting the ratio in descending order;
    sort(ratio.begin(),ratio.end(),compare);
  //adding element to the KnapSack in fractional manner;
    int ans=0;
    for(int i=0;i<n;i++){
      int idx=ratio[i].second;
      if(wt[idx]<=W){
         ans+=value[idx];
         W-=wt[idx];
      }
      else{
        ans+=ratio[i].first*W;
        W=0;
        break;
      }
    }
   return ans;
}

int main(){
  vector<int> value={60,100,120};
  vector<int> Wt={10,20,30};
  int capacity=50;
  
  cout<<"maximum value is: "<<Fractional_Knapsack(value,Wt,capacity);
  return 0;
}