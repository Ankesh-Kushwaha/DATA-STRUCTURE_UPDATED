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
   l=new list<int>[V];
  }

  void addedge(int u,int v){
     l[u].push_back(v);
     l[v].push_back(u);
  }

  bool isBipartite1(){
   vector<int> col(V,-1);
   vector<bool> vis(V,false);
   queue<int> q;
   q.push(0);
   vis[0]=true;
   col[0]=0; //assing colour=blue;

   while(!q.empty()){
    int curr=q.front();
    q.pop();
    list<int> neighbour=l[curr];
    for(int v:neighbour){
      if(!vis[v]){  //if the neighbour is not visited
        vis[v]=true;  //make it visited
        col[v]= !col[curr]; //assing it diffent color diffrent form curr
        q.push(v);
      }
      else{
        if(col[v]==col[curr]){ //condition for non-bipartite graph
          return false;
        }
      }
    }
   }
   return true;
  }

  //modified by using only one vector
  bool isBipartite2(){
    vector<int> col(V,-1);
    queue<int> q;
    q.push(0);
    col[0]=0; //assinging blue color
    while(!q.empty()){
      int curr=q.front();
      q.pop();
      list<int> neighbour=l[curr];
      for(auto v:neighbour){
        if(col[v]==-1){ //condition of not- visited
          col[v]=!col[curr];
          q.push(v);
        }
        else{
          if(col[v]==col[curr]){ //conditon for non - bipartite;
             return false;
          }
        }
      }
    }
    return true;
  }

  //bipartite 2nd approach
  bool isBipartiteHelper(int src,int par,vector<bool> &vis){
    vis[src]=true;
    list<int> neighbour=l[src];
    for(auto v:neighbour){
      if(!vis[v]){
      if(isBipartiteHelper(v,src,vis) && V%2==0){
         return true;
      }
      }
      else{
        if(v!=par){
          return true;
        }
      }
    }
    return false;
  }
  
  bool isBipartite(){
    vector<bool> vis(V,false);
    return isBipartiteHelper(0,-1,vis);
  }

};
int main(){
  Graph gp(4);
  gp.addedge(0,1);
  gp.addedge(1,3);
  gp.addedge(0,2);
  gp.addedge(3,2);
  gp.addedge(0,3);
  cout<<gp.isBipartite()<<endl;
  return 0;
}