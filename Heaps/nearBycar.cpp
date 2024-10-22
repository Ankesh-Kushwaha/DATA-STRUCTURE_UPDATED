#include <iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class car{
  public:
  int idx;
  int distSq;

  car(int idx,int distSq){
    this-> idx=idx;
    this->distSq=distSq;
  }

  bool operator < (const car &obj) const{
     return this->distSq > obj.distSq;//minHeap;
  }
};

void nearBycar(vector<pair<int,int>> pos,int K){
 vector<car> Cars;
 for(int i=0;i<pos.size();i++){
  int distSq=pos[i].first* pos[i].first+pos[i].second * pos[i].second;
  Cars.push_back(car(i,distSq));
 }

 priority_queue<car> pq(Cars.begin(),Cars.end());

 for(int i=0;i<K;i++){
  cout<<"car: "<<pq.top().idx<<endl;
  pq.pop();
 }
}
int main(){
vector<pair<int,int>> pos;
pos.push_back(make_pair(3,-3));
pos.push_back(make_pair(-2,4));
pos.push_back(make_pair(5,-1));
int K=2;
nearBycar(pos,K);
  return 0;
}
