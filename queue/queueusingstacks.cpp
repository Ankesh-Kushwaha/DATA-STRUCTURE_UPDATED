#include<iostream>
#include<stack>
using namespace std;
class queue{
  stack<int>s2;
  stack<int>s1;
 public:
  void push(int data){
      while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
      }
                     //done in linear time complexity;
      s1.push(data);

      while(!s2.empty()){
        s1.push(s2.top());
        s2.pop(); 
      }
  }

  void pop(){
      s1.pop();  //done in ->O(1);
  }

  int front(){
    return s1.top(); //done in ->O(1);
  }

 bool empty(){
   return s1.empty();
 }
};
int main(){
 queue q1;
 for(int i=0;i<8;i++){
  q1.push(i);
 }

 while(!q1.empty()){
    cout<<q1.front()<<endl;
    q1.pop();
 }
  return 0;
}