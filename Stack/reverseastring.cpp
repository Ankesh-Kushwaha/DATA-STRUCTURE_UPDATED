#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
  stack<char>s;

  string st="Ankesh Kushwaha";
  for(int i=0;i<st.length();i++){
     s.push(st[i]);
  }

  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
  cout<<endl;
  return 0;
}