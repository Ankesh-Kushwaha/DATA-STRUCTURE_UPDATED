#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int mergeRope(vector<int> ropes){
  priority_queue<int,vector<int> ,greater<int>> pq(ropes.begin(),ropes.end());
  int minCost=0;
  while(pq.size()>1){
    int min1=pq.top();
    pq.pop();
    int min2=pq.top();
    pq.pop();

    minCost+=min1+min2;
    pq.push(min1+min2);
  }

  cout<<"mininmum cost to merge:"<<minCost<<endl;
  return minCost;

}
int main(){
  vector<int> ropes={4,3,2,6};
  cout<<mergeRope(ropes)<<endl;
  return 0;
}