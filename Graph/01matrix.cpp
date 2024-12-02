#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
  vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}; // given graph;
  int n = mat.size();
  int m = mat[0].size();

  vector<vector<int>> vis(n, vector<int>(m, 0)); //set a visited vector to show the connection
  vector<vector<int>> dist(n, vector<int>(m, 0)); // vector to store the result array;

  queue<pair<pair<int, int>, int>> q;

  for (int i = 0; i < n;i++){
    for (int j = 0; j < m;j++){
        if(mat[i][j]==0){
          vis[i][j] = 1;
          q.push({{i, j}, 0});
        }
        else{
          vis[i][j] = 0;
        }
    }
  }

  vector<int> dx = {-1,0,1,0}; //vectors to traverse the matrix in x direction
  vector<int> dy = {0,1,0,-1};//vector to traverse the matrix in y direction

  while(!q.empty()){
    int x = q.front().first.first;
    int y = q.front().first.second;
    int steps = q.front().second;
    q.pop();
    dist[x][y] = steps;

    for (int i = 0; i < 4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
       if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0){
         vis[nx][ny] = 1;
         q.push({{nx, ny}, steps + 1});
       }
    }
  }

  for (int i = 0; i < n;i++){
    for (int j = 0; j < m;j++){
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }
    return 0;
}