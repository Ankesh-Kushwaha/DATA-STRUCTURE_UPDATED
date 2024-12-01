#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class edge{
  public:
  int v;
  int wt;
  edge(int v,int wt){
    this->v = v;
    this->wt = wt;
  }
};

void DijktrasAlgo(int src,int V,vector<vector<edge>> graph){
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // contain dist[v],v;
  vector<int> dist(V, INT32_MAX);
  dist[src] = 0;
  pq.push(make_pair(0,src));
  while(pq.size()>0){
    int u = pq.top().second;
    pq.pop();

    vector<edge> neighbour = graph[u];
    for(auto e:neighbour){
        if(dist[e.v]>dist[u]+e.wt){
          dist[e.v] = dist[u] + e.wt;
          pq.push(make_pair(dist[e.v],e.v));
        }
    }
  }

  for(auto d:dist){
    cout << d << " ";
  }
  cout << endl;
}

int main(){
  int node = 6;
  vector<vector<edge>> g(node);

  g[0].push_back(edge(1, 2));
  g[0].push_back(edge(2, 4));

  g[1].push_back(edge(3,7));
  g[1].push_back(edge(2, 1));

  g[2].push_back(edge(4,3));
  g[3].push_back(edge(5, 1));

  g[4].push_back(edge(3,2));
  g[4].push_back(edge(5,5));

  DijktrasAlgo(0, 6, g);
  return 0;
}