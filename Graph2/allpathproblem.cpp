#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{
  int V;
  list<int> *l;
  public:
  Graph(int V){
   this->V=V;
   l=new list<int> [V];
  }

  void addedge(int u,int v){
  l[u].push_back(v);
  }

  void printpathHelper(int src,int dest,string path,vector<bool> &vis){
    //base case 
    if(src==dest){
      cout<<path<<dest<<endl;
      return;
    }

    vis[src]=true;
    path+=to_string(src);
    list<int> neighbour=l[src];
    for(auto v:neighbour){
      if(!vis[v]){
        printpathHelper(v,dest,path,vis);
      }
    }
    path=path.substr(0,path.size()-1); //bactrack
    vis[src]=false;                    //backtrack
  }

  void printpath(int src,int dest){
   vector<bool> vis(V,false);
   string path="";
   printpathHelper(src,dest,path,vis);
  }
};
int main(){
Graph gp(6);
gp.addedge(5,0);
gp.addedge(5,2);
gp.addedge(2,3);
gp.addedge(0,3);
gp.addedge(3,1);
gp.addedge(4,1);
gp.addedge(4,0);

gp.printpath(5,1);
  return 0;
}