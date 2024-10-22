#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class edge{
 public:
 int u;
 int v;
 int wt;

 edge(int u,int v,int wt){
  this->u=u;
  this->v=v;
  this->wt=wt;
 }
};

class Graph{
  int V;
  vector<edge> edges;
  public:
  vector<int> par;
  vector<int> rank;
  Graph(int V){
    this->V=V;

    for(int i=0;i<V;i++){
      par.push_back(i);
      rank.push_back(0);
    }
  }

  void addedge(int u,int v,int wt){
     edges.push_back(edge(u,v,wt));
  }

 int find(int x){
   if(par[x]==x){
    return x;
   }
   return par[x]=find(par[x]);
 }

 int UnionByRank(int u,int v){
   int parU=find(u);
   int parV=find(v);

   if(rank[parU]==rank[parV]){
    par[parV]=parU;
    rank[parU]++;
   }
   else if(rank[parU]>rank[parV]){
       par[parV]=parU;
   }
   else{
    par[parV]=parU;
   }
 }

  void kruskal(){
     sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) {
        return a.wt < b.wt;
    });
    int ans=0;
    int count=0;
    for(int i=0;i<V && count<V-1;i++){
    auto e=edges[i];
    int parU=find(e.u);
    int parV=find(e.v);
     if(parU!=parV){
      UnionByRank(parU,parV);
       ans+=e.wt;
       count++;
     }
    }

    cout<<"minimum WT:"<<ans<<endl;
  }
};

int main(){
 Graph gp(4);
 gp.addedge(0,1,10);
 gp.addedge(1,3,40);
 gp.addedge(0,3,30);
 gp.addedge(0,2,15);
 gp.addedge(3,2,50);

 gp.kruskal();
  return 0;
}