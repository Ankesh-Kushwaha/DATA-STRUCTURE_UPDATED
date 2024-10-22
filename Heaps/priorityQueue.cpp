#include <iostream>
#include<queue>
using namespace std;
int main(){
priority_queue<int,vector<int>,greater<int>> pq;
for(int i=0;i<=10;i++){
  pq.push(i);
}

while(!pq.empty()){
  cout<<"top :"<<pq.top()<<endl;
  pq.pop();
}
  return 0;
}