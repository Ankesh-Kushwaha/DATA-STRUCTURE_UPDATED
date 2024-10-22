#include <iostream>
#include<queue>
#include<stack>
using namespace std;

void queueReversal(queue<int> &Q){
   stack<int>s;
   while(!Q.empty()){
     s.push(Q.front());
     Q.pop();
   }

   while(!s.empty()){
     Q.push(s.top());
     s.pop();
   }

}

int main(){
queue<int>Q;
for(int i=0;i<10;i++){
  Q.push(i);
}
queueReversal(Q);

while(!Q.empty()){
  cout<<Q.front()<<" ";
  Q.pop();
}
cout<<endl;
  return 0;
}