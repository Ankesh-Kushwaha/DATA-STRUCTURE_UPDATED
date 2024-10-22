#include <iostream>
#include <vector>
using namespace std;
//creating stack using vector;
template<class T>
class stack{
   vector<T>vec;
public:
  void push(T val){
      vec.push_back(val);
  }

  void pop(){
    if(isEmpty()){
     cout<<"stack is empty:"<<endl;
     return ;
    }
     vec.pop_back();
  }   

  T top(){
    //  if(isEmpty()){
    //  cout<<"stack is empty:"<<endl;
    //  return -1;
    // }
    int lastIdx=vec.size()-1;
    return vec[lastIdx];
  }

  bool isEmpty(){
    return vec.size()==0;
  }

};
int main(){
  stack<int> s;
  stack<char> s1;
  s.push(3);
  s.push(2);
  s.push(1);
  s.push(0);
  
  while(!s.isEmpty()){
    cout<<(s.top())<<" ";
    s.pop();
  }

cout<<endl;
  s1.push('A');
  s1.push('B');
  s1.push('C');
  s1.push('D');
  s1.push('E');

  while(!s1.isEmpty()){
    cout<<(s1.top())<<" ";
    s1.pop();
  }
  cout<<endl;
  stack<string> s2;
  s2.push("Ankesh");
  s2.push("Kushwaha");
  s2.push("Becomes");
  s2.push("A");
  s2.push("Great");
  s2.push("Coder");
  
   while(!s2.isEmpty()){
    cout<<(s2.top())<<" ";
    s2.pop();
  }
  return 0;
}