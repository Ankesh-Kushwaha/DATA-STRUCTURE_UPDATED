#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int solve(vector<vector<int>> board,string target){
  string start = "";
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 3;j++){
      start += to_string(board[i][j]);
    }
  }

  unordered_map<int, vector<int>> mp; //making the adjacency list
  mp[0] = {1,3};
  mp[1] = {0,2,4};
  mp[2] = {1,5};
  mp[3] = {0,4};
  mp[4] = {1,3,5};
  mp[5] = {2,4};

  //starting BFS
  queue<string> q;
  q.push(start);
  //declaring visited array
  unordered_set<string> visited;
  visited.insert(start);
  int level = 0;
  while(!q.empty()){
    int n = q.size();
     while(n--){
       string curr = q.front();
       q.pop();
       cout << curr << endl;
       if(curr==target){
         return level;
       }

       int zeroIdx = curr.find('0');
       for(auto swapIdx:mp[zeroIdx]){
         string newState = curr;
         swap(newState[zeroIdx], newState[swapIdx]);
         if(visited.find(newState)==visited.end()){
           q.push(newState);
           visited.insert(newState);
         }
       }
       
     }
     level++;
  }
  return -1;
}

int main(){
  vector<vector<int>> board = {{4,1,2},{5,0,3}};
  string target = "123450";
  cout << "required no of swaps to solve puzzle:" << solve(board, target) << endl;
  return 0;
}