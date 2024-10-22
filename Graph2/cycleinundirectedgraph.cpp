#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Graph{
int V;
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

bool isCycleHelper(int src,int par,vector<bool> &vis){
 vis[src]=true;
 list<int > neighbour=l[src];
 for(auto v:neighbour){
  if(!vis[v]){
    if(isCycleHelper(v,src,vis)){
      return true;
    }
  }
  else{
    if(v!=par){ //condititon for cycle detection
      return true;
    }
  }
 }
 return false;
}

bool isCycle(){
  vector<bool> vis(V,false);
  return isCycleHelper(0,-1,vis);
}

};

int main(){
Graph gp(5);
gp.addedge(0,1);
gp.addedge(0,2);
gp.addedge(0,3);
gp.addedge(1,2);
gp.addedge(3,4);
cout<<gp.isCycle()<<endl;
  return 0;
}