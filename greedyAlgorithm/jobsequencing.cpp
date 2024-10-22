#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int>p2){
  return p1.second>p2.second;
}

int maximize_profit(vector<pair<int,int>> jobs){
  int n=jobs.size();
  sort(jobs.begin(),jobs.end(),compare);
  
  //picking up job at 0th index;
  int profit=jobs[0].second;
  int safe_deadline=2;
  for(int i=1;i<n;i++){
    if(jobs[i].first>=safe_deadline){
        profit+=jobs[i].second;
        safe_deadline++;
    }
  }
  return profit;
}

int main(){
  vector<pair<int,int>>jobs(4,make_pair(0,0));
  jobs[0]=make_pair(4,20);
  jobs[1]=make_pair(1,10);
  jobs[2]=make_pair(1,40);
  jobs[3]=make_pair(1,30);
  
  cout<<"maximum required profit:"<<maximize_profit(jobs)<<endl;
  return 0;
}