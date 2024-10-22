#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
 int V;
 list<int>* l;
 bool isUndirec;
public:
 Graph(int V,bool isUndirec=true){
   this->V=V;
   l=new list<int> [V];
   this->isUndirec=isUndirec;
 }

 void addedge(int u,int v){
  l[u].push_back(v);
  if(isUndirec){
    l[v].push_back(u);
  }
 }


bool isCycleDirHelper(int src,vector<bool> &vis,vector<bool> &recPath){
 vis[src]=true;
 recPath[src]=true;
 list<int> neighbour=l[src];
 for(auto v:neighbour){
  if(!vis[v]){
    if(isCycleDirHelper(v,vis,recPath)){
      return true;
    }
  }
  else{
    if(recPath[v]){//already visited and present in recursion path
      return true;
    }
  }
 }
 recPath[src]=false;
 return false;
}
bool isCycleDir(){
  vector<bool> vis(V,false);
  vector<bool> recPath(V,false);
  for(int i=0;i<vis.size();i++){
    if(isCycleDirHelper(i,vis,recPath)){
      return true;
    } 
  }
  return false;
}
};
int main(){
Graph gp(4,false);
gp.addedge(1,0);
gp.addedge(3,0);
gp.addedge(2,3);
gp.addedge(0,2);
cout<<gp.isCycleDir()<<endl;
  return 0;
}