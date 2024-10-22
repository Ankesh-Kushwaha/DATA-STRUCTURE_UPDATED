#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
  int V;
  list<int> *l;
  public:
  Graph(int V){
   this->V=V;
   l=new list<int>[V];
  }

  void addedge(int u,int v){
   l[u].push_back(v);
   l[v].push_back(u);
  }
  
  void dfsHelper(int u,vector<bool> &vis){
    vis[u]=true;
    cout<<u<<" ";
    list<int> neighbour=l[u];
    for(int v: neighbour){
      if(!vis[v]){
        dfsHelper(v,vis);
      }
    }
  }

  void dfs(){
    vector<bool> vis(7,false);
    dfsHelper(0,vis);
    cout<<endl;
  }
};
int main(){
   Graph gp(7);
 gp.addedge(0,1);
 gp.addedge(0,2);
 gp.addedge(1,3);
 gp.addedge(2,4);
 gp.addedge(3,4);
 gp.addedge(3,5);
 gp.addedge(4,5);
 gp.addedge(5,6);
 gp.dfs();
  return 0;
}