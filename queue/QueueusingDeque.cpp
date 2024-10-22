#include <iostream>
#include<deque>
using namespace std;

class queue{
  deque<int>deq;
 public:
 void push(int data){
    deq.push_back(data);
 }

 void pop(){
   deq.pop_front();
 }

 int front(){
   return deq.front();
 }

 bool empty(){
  return deq.empty();
 }
};
int main(){
queue q;
for(int i=1;i<=10;i++){
  q.push(i);
}

while(!q.empty()){
   cout<<q.front()<<endl;
   q.pop();
}
  return 0;
}