#include <iostream>
#include <deque>
using namespace std;

class stack{
  deque<int>deq;
 public:
  void push(int data){
     deq.push_back(data);
  }

  void pop(){
     deq.pop_back();
  }

  int top(){
      return deq.back();
  }

  bool empty(){
     return deq.empty();
  }
};

int main(){
stack s;
for(int i=0;i<10;i++){
  s.push(i);
}

while(!s.empty()){
  cout<<s.top()<<endl;
  s.pop();
}
  return 0;
}