#include<iostream>
#include<stack>
using namespace std;
void pushAtBottom(stack<int> &s,int val){
 
 //base case
 if(s.empty()){
    s.push(val);
    return ;
 }

  int temp=s.top();
  s.pop();
  pushAtBottom(s,val);
  s.push(temp); //backtrack;
}
void reverse(stack<int> &s){
  //base case
  if(s.empty()){
    return ;
  }

  int temp=s.top();
  s.pop();
  reverse(s);
  pushAtBottom(s,temp); //backtrack

}

void print_stack(stack<int> s){
  cout<<"REVERSE STACK:->"<<endl;
  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<endl;
}
int main(){
stack<int>s;
for(int i=0;i<8;i++){
  s.push(i);
}
print_stack(s);
reverse(s);
print_stack(s);
  return 0;
}