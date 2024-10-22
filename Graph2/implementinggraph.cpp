#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
//undirected unweighted graph
class Graph{
 int V;
 list<int>* l;
 public:
 Graph(int V){
  this->V=V;
  l=new list<int> [V];
 }

 void addedge(int u,int v){ //u---v
   l[u].push_back(v);
   l[v].push_back(u);
 }

 void print(){
  for(int u=0;u<V;u++){
    list<int> neighbour=l[u];
    cout<<u<<":";
    for(auto v: neighbour){
      cout<<v<<" ";
    }
    cout<<endl;
  }
 }

 void BFS(){
  queue<int> q;
  vector<bool> vis(V,false);

  q.push(0);
  vis[0]=true;
  while(!q.empty()){
    int u=q.front(); //node u
    q.pop();
    cout<<u<<" ";
    list<int> neighbour=l[u];
    for(auto v:neighbour){
      if(!vis[v]){
        vis[v]=true;
        q.push(v);
      }
    }
  }
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
    dfsHelper(0,vis);
 }
};

//undirected weighted graph
class Graph2{
 int V;
 list<pair<int,int>>* l;
public:
 Graph2(int V){
   this->V=V;
   l=new list<pair<int,int>> [V];
 }

 void addedge(int u,int v,int wt){ //u--------v and wt=weight
  l[u].push_back(make_pair(v,wt));
  l[v].push_back(make_pair(u,wt));
 }

void print(){
  for(int u=0;u<V;u++){
    list<pair<int,int>> neighbour=l[u];
    cout<<u<<":";
    for(auto v:neighbour){
      cout<<"("<<v.first<<","<<v.second<<")"<<" ";
    }
    cout<<endl;
  }
}
};

//directed graph
class Graph3{
  int V;
  list<int> *l;
  public:
  Graph3(int V){
   this->V=V;
   l=new list<int> [V];
  }

  void addedge(int u,int v){
    l[u].push_back(v);
  }

   void print(){
  for(int u=0;u<V;u++){
    list<int> neighbour=l[u];
    cout<<u<<":";
    for(auto v: neighbour){
      cout<<v<<" ";
    }
    cout<<endl;
  }
 }
 
};

int main(){
  // Graph2 graph(5);
  // graph.addedge(0,1,5);
  // graph.addedge(1,2,1);
  // graph.addedge(2,3,1);
  // graph.addedge(1,3,3);
  // graph.addedge(2,4,2);
  // graph.print();

  // Graph3 graph(5);
  // graph.addedge(0,1);
  // graph.addedge(1,2);
  // graph.addedge(2,3);
  // graph.addedge(3,1);
  // graph.print();
  Graph graph(8);
  graph.addedge(0,1);
  graph.addedge(0,2);
  graph.addedge(1,3);
  graph.addedge(2,4);
  graph.addedge(3,4);
  graph.addedge(3,5);
  graph.addedge(4,5);
  graph.addedge(5,6);
  graph.dfs();
  return 0;
}