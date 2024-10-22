#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2){
  return p1.second<p2.second;
}

int maxLengthChain(vector<pair<int,int>> pairs){
  int n=pairs.size();
  sort(pairs.begin(),pairs.end(),compare);
  int count=1;
  int curr_end=pairs[0].second;
  for(int i=1;i<n;i++){
    if(pairs[i].first>curr_end){
      count++;
      curr_end=pairs[i].second;
    }
  }
  return count;
}

int main() {
    int n = 5;
    vector<pair<int, int>> pairs(n, {0, 0}); 
    pairs[0]=make_pair(5,24);
    pairs[1]=make_pair(39,60);
    pairs[2]=make_pair(5,28);
    pairs[3]=make_pair(27,40);
    pairs[4]=make_pair(50,90);

    cout<<"maximum length of chain is :"<<maxLengthChain(pairs)<<endl;
    return 0;
}
