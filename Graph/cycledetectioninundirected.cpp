#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class graph{
  int V;
  list<int> *l;
  public:
  graph(int V){
    this->V = V;
    l = new list<int>[V];
  }

  void addedge(int u, int v){
    l[u].push_back(v);
    l[v].push_back(u);
  }

  bool cycleUndirHelper(int src, int par, vector<bool> &vis){
    vis[src] = true;
    for(auto v : l[src]){
      if(!vis[v]){
        if(cycleUndirHelper(v, src, vis)){
          return true;
        }
      }
      else if(v != par){
        return true;
      }
    }
    return false;
  }

  bool cycleUndir(){
    vector<bool> vis(V, false);
    for(int i = 0; i < V; ++i) {
      if(!vis[i]) {
        if(cycleUndirHelper(i, -1, vis)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main(){
  graph gp(5);
  gp.addedge(0, 1);
  gp.addedge(0,2);
  gp.addedge(0, 3);
  gp.addedge(1, 2);
  gp.addedge(3, 4);
  cout << gp.cycleUndir() << endl; // Expected output: 0 (false)
  return 0;
}
