#include<iostream>
#include<queue>
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
  
  bool pathHelper(int src,int des ,vector<bool> &vis){
   if(src==des){
    return true;
   } 
   vis[src]=true;
   list<int> neighbour=l[src];

   for(int v: neighbour){
       if(!vis[v]){
        if(pathHelper(v,des,vis)){
          return true;
        }
       }
   }
   return false;
  }

  bool path(int src,int des){
     vector<bool> vis(V,false);
     return pathHelper(src,des,vis);
  }


bool bfs(int src,int des){
  queue<int> q;
  vector<bool> vis(V,false);
  q.push(src);
  vis[src]=true;

  while(q.size()>0){
    int curr=q.front();
    q.pop();
   if(curr==des){
     return true;
   }
    list<int> neighbour=l[curr];
    for(int v: neighbour){
      if(!vis[v]){
        vis[v]=true;
        q.push(v);
      }
    }
  }
  return false;
}
};

int main(){
 Graph gp(7);
 gp.addedge(0,1);
 gp.addedge(0,2);
 gp.addedge(1,3);
 gp.addedge(3,4);
 gp.addedge(2,4);
 gp.addedge(3,5);
 gp.addedge(4,5);
 gp.addedge(5,6);

 cout<<gp.bfs(5,7)<<endl;
  return 0;
}