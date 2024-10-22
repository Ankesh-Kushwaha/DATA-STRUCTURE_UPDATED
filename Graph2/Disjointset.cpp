#include<iostream>
#include<vector>
using namespace std;

class disjoint{
  public:  
  int n;
  vector<int> par;
  vector<int> rank;
  
  disjoint(int n){
    this->n=n;
    for(int i=0;i<n;i++){
      par.push_back(i);
      rank.push_back(0);
    }
  }

  int find(int x){
    if(par[x]==x){
      return x;
    }

    return par[x]=find(par[x]);  //path compresion;
  }

  void unionByRank(int a,int b){
      int parA=find(a);
      int parB=find(b);

      if(rank[parA]==rank[parB]){
           par[parB]=parA;
           rank[parA]++;
      }
      else if(rank[parA]>rank[parB]){
           par[parB]=parA;
      }
      else{
        par[parA]=parB;
      }
  }

  void print(){
    for(int i=0;i<n;i++){
      cout<<"par:"<<par[i]<<" "<<"rank:"<<rank[i]<<endl;
    }
  }
};
int main(){
   disjoint dj(6);
   dj.unionByRank(0,2);
   cout<<dj.find(2)<<endl;
   dj.unionByRank(1,3);
   dj.unionByRank(2,5);
   dj.unionByRank(0,3);
   cout<<dj.find(2)<<endl;
   dj.unionByRank(0,4);
   dj.print();

  return 0;
}