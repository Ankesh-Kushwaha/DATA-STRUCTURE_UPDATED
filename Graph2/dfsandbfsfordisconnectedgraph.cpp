#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph{
  int V;//no of nodes
  list<int>* l;
  public:
  Graph(int V){
   this->V=V;
   l=new list<int> [V];
  }

  void addedge(int u,int v){
    l[u].push_back(v);
    l[v].push_back(u);
  }

void dfsHelper(int u,vector<bool> &vis){
  vis[u]=true;
  cout<<u<<" ";
  list<int> neighbour=l[u];
  for(auto v:neighbour){
      if(!vis[v]){
        dfsHelper(v,vis);
      }
  }
}
  void dfs(){
    vector<bool> vis(V,false);
    for(int i=0;i<vis.size();i++){
      if(!vis[i]){
       dfsHelper(i,vis);
      }
    }
  }

void bfsHelper(int u,vector<bool> &vis){
  queue<int> q;
  q.push(u);
  vis[u]=true;
  while(!q.empty()){
    int curr=q.front();
    q.pop();
    cout<<curr<<" ";
    list<int> neighbour=l[u];
    for(auto v:neighbour){
        if(!vis[v]){
          vis[v]=true;
          q.push(v);
        }
    }
  }
}
  void bfs(){
    vector<bool> vis(V,false);
    for(int u=0;u<vis.size();u++){
      if(!vis[u]){
        bfsHelper(u,vis);
      }
    }
  }

};
int main(){
  Graph gp(10);
gp.addedge(1, 6);
  gp.addedge(6, 4);
  gp.addedge(4, 3);
  gp.addedge(4, 9);
  gp.addedge(3, 7);
  gp.addedge(3, 8);
  gp.addedge(0, 2);
  gp.addedge(2, 5);

  cout<<"DFS Traversal of graph is:"<<endl;
  gp.dfs();
  cout<<"BFS traversal of graph is:"<<endl;
  gp.bfs();
  return 0;
}