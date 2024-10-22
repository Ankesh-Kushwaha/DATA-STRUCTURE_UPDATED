#include <iostream>
#include<queue>
using namespace std;

struct comparePair{
  bool operator()(pair<string,int> &p1 ,pair<string,int> &p2){
    return p1.second < p2.second ;
  }
};
int main(){
priority_queue<pair<string,int>,vector<pair<string,int>>,comparePair> pq;
pq.push(make_pair("ankesh",844)); //on default it makes max PQ on the behalf of its first value;
pq.push(make_pair("cyush",740));
pq.push(make_pair("rjay",600));


while(!pq.empty()){
  cout<<"name: "<<pq.top().first<<" marks: "<<pq.top().second<<endl;
  pq.pop();
}
  return 0;
}