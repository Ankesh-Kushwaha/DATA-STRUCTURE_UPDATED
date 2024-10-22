#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void slidingWindow(vector<int> window,int k){
  priority_queue<pair<int,int>>pq;

  for(int i=0;i<k;i++){
    pq.push(make_pair(window[i],i));
  }

 cout<<pq.top().first<<" ";
 for(int i=k;i<window.size();i++){
      while(!pq.empty() && pq.top().second<=i-k){
        pq.pop();
      }

      pq.push(make_pair(window[i],i));
      cout<<pq.top().first<<" ";
 }
 cout<<endl;
}
int main(){
vector<int> window={1,3,-1,-3,5,3,6,7};
slidingWindow(window,4);
  return 0;

}