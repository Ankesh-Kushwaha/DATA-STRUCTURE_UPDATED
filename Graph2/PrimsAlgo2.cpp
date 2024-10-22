#include <iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class edge_info{
   int u;
   int v;
   int wt;
   public:
   edge_info(int u,int v,int wt){
       this->u=u;
       this->v=v;
       this->wt=wt;
   }

   int getU() const{
    return u;
   }

   int getV() const{
    return v;
   }

   int getWt() const{
        return wt;
   }
};

class graph{
  int V;
  list<pair<int,int>> *l;
  bool isUndir;

  public:
  graph(int V,bool isUndir=true){
    this->V=V;
    l=new list<pair<int,int>> [V];
    this->isUndir=isUndir;
  }

  void addedge(int u,int v,int wt){
     l[u].push_back(make_pair(v,wt));
     if(!isUndir){
        l[v].push_back(make_pair(u,wt));
     }
  }

 void PrimsAlgo(int src){
  priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  vector<bool> MST(V,false);
  vector<edge_info> info;

  pq.push(make_pair(0,src)); // 1.wt  2.src
  int ans=0;

  while(!pq.empty()){
    int curr=pq.top().second;
    int wt=pq.top().first;
    pq.pop();
    if(!MST[curr]){
      MST[curr]=true;
      ans+=wt;

      list<pair<int,int>> neighbour=l[curr];
      for(auto edge:neighbour){
          pq.push(make_pair(edge.second,edge.first));
          info.push_back(edge_info(curr,edge.first,edge.second));
      }
    }
  }
  cout<<"minimum cost is :"<<ans<<endl;

  for(auto edge:info){
    cout<<"edge :"<<"("<<edge.getU()<<","<<edge.getV()<<")"<<"weight:"<<edge.getWt()<<endl;
  }
 }
};
int main(){
 graph gp(4);

gp.addedge(0,1,10);
gp.addedge(0,3,30);
gp.addedge(0,2,15);

gp.addedge(1,3,40);
gp.addedge(3,2,50);

gp.PrimsAlgo(0);
  return 0;
}