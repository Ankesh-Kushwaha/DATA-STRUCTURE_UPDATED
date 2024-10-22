#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class edge{
  public:
  int v;
  int wt;
  edge(int v,int wt){
    this->v=v;
    this->wt=wt;
  }

};

void DijkstrasAlgo(int src,vector<vector<edge>> graph,int V){
   priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> pq;//contain dist[v],v;
   vector<int> dist(V,INT32_MAX);
  
  pq.push(make_pair(0,src));
  dist[src]=0;

  while(pq.size()>0){
    int u=pq.top().second;
    pq.pop();
    
    vector<edge> neighbour=graph[u];
    for(auto e:neighbour){
       if(dist[e.v]>dist[u]+e.wt){
         dist[e.v]=dist[u]+e.wt;
         pq.push(make_pair(dist[e.v],e.v));
       }
    }
  }
  
  for(auto d:dist){
    cout<<d<<" ";
  }
  cout<<endl;
}
int main(){
int V=6;
vector<vector<edge>> graph(V);

graph[0].push_back(edge(1,2));
graph[0].push_back(edge(2,4));

graph[1].push_back(edge(3,7));
graph[1].push_back(edge(2,1));

graph[2].push_back(edge(4,3));

graph[3].push_back(edge(5,1));

graph[4].push_back(edge(3,2));
graph[4].push_back(edge(5,5));

DijkstrasAlgo(5,graph,V);
  return 0;
}