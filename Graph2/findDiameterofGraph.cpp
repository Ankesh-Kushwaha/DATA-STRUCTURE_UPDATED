#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

/**
 * @brief Performs a Breadth-First Search (BFS) on a graph to find the farthest node and the diameter from a given source node.
 * if you choose a random node and find the farthest node from it, then the farthest node from the farthest node is the diameter of the graph.
 * u----------------->(farthest node)--------------->v;
 * v----------------->(farthest node)--------------->one end of the diameter;
 * diameter = 2;
 *
 * @param n The number of nodes in the graph.
 * @param adj The adjacency list representing the graph.
 * @param src The source node from which BFS starts.
 * @return A pair containing the farthest node from the source and the diameter of the graph.
 */

pair<int,int> bfs(int n ,vector<list<int>> &adj,int src){
  vector<int> vis(n, 0);
  queue<int> q;
  q.push(src);
  vis[src] = 1;
  int LastNode = src;
  int diameter = 0;

  while(!q.empty()){
    int levelSize = q.size();
    
    while(levelSize--){
      int node = q.front();
      q.pop();
      LastNode = node;

      for(const auto& i : adj[node]){
        if(!vis[i]){
          vis[i] = 1;
          q.push(i);
        }
      }
    }
    if(!q.empty()){
      diameter++;
    }
  }

  return {LastNode, diameter};
}

int findDiameter(vector<list<int>> &adj,int n){
  //find the farthest node from any random node
  pair<int, int> result = bfs(n, adj, 0);
  int farthestNode = result.first;
  int diameter = result.second;
  // find the farthest node from the farthest node
  result = bfs(n, adj, farthestNode);
  diameter = result.second;
  return diameter;
} 

int main(){
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}};

  int n = 4;
  vector<list<int>> adj(n);
  for(auto edge:edges){
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  }

  int diameter = findDiameter(adj,n);
  cout << diameter << endl;

  return 0;
}