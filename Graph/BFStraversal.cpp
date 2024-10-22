#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph{
  int V;
  list<int> *l;
  public:
  Graph(int V){
  this->V=V;
  l=new list<int>[V];
  }

  void addedge(int u,int v){ //u---v
    l[u].push_back(v);
    l[v].push_back(u);
  }

  void bfs(){
    queue<int> q;
    vector<bool> vis(V,false);
    
    q.push(0);
    vis[0]=true;
     
    while(q.size()>0){
      int u=q.front();
      q.pop();
      cout<<u<<" ";
      list<int> neighbour=l[u];//u--v
      for(int v:neighbour){
       if(!vis[v]){
          vis[v]=true;
        q.push(v);
       }
      }
    } 
    
  }

};
int main(){
//  Graph gp(7);
//  gp.addedge(0,1);
//  gp.addedge(0,2);
//  gp.addedge(1,3);
//  gp.addedge(2,4);
//  gp.addedge(3,4);
//  gp.addedge(3,5);
//  gp.addedge(4,5);
//  gp.addedge(5,6);
Graph gp(5);
gp.addedge(0,1);
gp.addedge(1,2);
gp.addedge(1,3);
gp.addedge(2,3);
gp.addedge(2,4);

 gp.bfs();
  return 0;
}