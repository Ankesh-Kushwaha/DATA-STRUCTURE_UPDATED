#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void topoSort(int src,vector<vector<pair<int,int>>> &graph,vector<int> &vis,stack<int> &st){
  vis[src] = 1;
  for(auto &it:graph[src]){
       if(!vis[it.first]){
         topoSort(it.first, graph, vis, st);
       }
  }

  st.push(src);
}

int main(){
  vector<vector<int>> mat = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
  int V = 6;
  int E = 7;
  vector<vector<pair<int, int>>> graph(V);
  for(auto &it:mat){
    graph[it[0]].push_back({it[1], it[2]});
  }

  stack<int> st;
  vector<int> vis(V, 0);
  topoSort(0,graph, vis, st);

  while(!st.empty()){
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}