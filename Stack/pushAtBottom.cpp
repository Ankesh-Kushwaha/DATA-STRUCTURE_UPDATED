#include <iostream>
#include<stack>
using namespace std;
void pushAtBottom(stack<int> &s,int val){
 // base case 
 if(s.empty()){ //time-Complexity=O(n);
  s.push(val);
  return;
 }

  int temp=s.top();
  s.pop();
  pushAtBottom(s,val);
  s.push(temp);
}

int main(){
  stack<int> s;
  for(int i=1;i<5;i++){
    s.push(i);
  }
  pushAtBottom(s,6);

  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<endl;
  return 0;
}