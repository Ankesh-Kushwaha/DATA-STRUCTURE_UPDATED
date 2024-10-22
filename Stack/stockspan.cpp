#include <iostream>
#include <stack>
#include<vector>
using namespace std;
void print(vector<int>span){
  for(int i=0;i<span.size();i++){
    cout<<span[i]<<" ";
  }
  cout<<endl;
}

void span_problem(vector<int> stock,vector<int> span){
  stack<int>s;
  span[0]=1;
  s.push(0);

  for(int i=1;i<stock.size();i++){
     while(!s.empty() && stock[s.top()]<=stock[i]){
       s.pop();
     }

      //special case
    if(s.empty()){
      span[i]=i+1;
    }
    else{
         int prevHigh=s.top();
       span[i]=i-prevHigh;
    }
  }
   print(span);
}


int main(){
 vector<int> stock={100,80,60,70,60,85,100};
 vector<int> span={0,0,0,0,0,0,0};
 span_problem(stock,span);
  return 0;
}