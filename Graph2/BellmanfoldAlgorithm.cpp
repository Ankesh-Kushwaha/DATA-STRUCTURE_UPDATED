#include<iostream>
#include<vector>
using namespace std;
class edge{
  public:
  int v; int wt;
  edge(int v,int wt){
    this->v=v; 
    this->wt=wt;
  }
};

void bellmanfoldAlgo(vector<vector<edge>> graph,int V,int src){
   vector<int> dist(V,INT32_MAX);
   dist[src]=0;

   for(int i=0;i<V-1;i++){  //traversing on all V-1 node
      for(int u=0;u<V;u++){ //traversing on each node;
            for(edge e:graph[u]){
               if(dist[u] != INT32_MAX && dist[e.v] > dist[u] + e.wt){
                   dist[e.v]=dist[u]+e.wt;
               }
            }
      } 
   }

   for(auto d:dist){
     cout<<d<<" ";
   }
}
int main(){
  //bellmanFold Algorithm
 int V=5;
 vector<vector<edge>> graph(V);
 
 graph[0].push_back(edge(1,2));
 graph[0].push_back(edge(2,4));

 graph[1].push_back(edge(2,-4));
 graph[2].push_back(edge(3,2));

 graph[3].push_back(edge(4,4));
 graph[4].push_back(edge(1,-1));
 bellmanfoldAlgo(graph,V,4);
  return 0;
}