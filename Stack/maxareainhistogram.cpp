#include <iostream>
#include<stack>
#include<vector>
using namespace std;

void print(vector<int> ans){
  cout<<endl;
 for(int i=0;i<ans.size();i++){
  cout<<ans[i]<<" ";
 }
 cout<<endl;
}

void maxHistogram(vector<int> height){
  int n=height.size();
  vector<int>nsL(n);
  vector<int>nsR(n);
  stack<int>s;
  
  //next smaller left;
  nsL[0]=-1;
  s.push(0);
  for(int i=0;i<height.size();i++){
      int curr=height[i];
      while(!s.empty() && curr<=height[s.top()]){
        s.pop();
      }

      if(s.empty()){
        nsL[i]=-1;
      }
      else{
        nsL[i]=s.top();
      }
      s.push(i);
  }
  
  while(!s.empty()){
    s.pop();
  }

  //next smaller right;
  nsR[n-1]=n;
  s.push(n);
  for(int i=n-2;i>=0;i--){
      int curr=height[i];
      while(!s.empty() && curr<=height[s.top()]){
        s.pop();
      }

      if(s.empty()){
        nsR[i]=n;
      } 
      else{
        nsR[i]=s.top();
      }
      s.push(i);
  }

 int maxArea=0;
 for(int i=0;i<n;i++){
   int ht=height[i];
   int wd=nsR[i]-nsL[i]-1;
   int area=ht*wd;
   maxArea=max(area,maxArea);
 }
 
 print(nsL);
 print(nsR);
 cout<<"maximum area required :"<<maxArea<<endl;
}


int main(){
  vector<int> height={2,1,5,6,2,3};
  maxHistogram(height);
  return 0;
}
