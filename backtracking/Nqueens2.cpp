#include<iostream>
#include<vector>
#include<string>
using namespace std;

void print(vector<vector<char>> board){
  for(int i=0;i<board.size();i++){
    for(int j=0;j<board.size();j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"_______________________"<<endl;
}
bool issafe(vector<vector<char>> board ,int row,int col){
  int n=board.size();
  //horizontal safety
  for(int i=0;i<n;i++){
    if(board[row][i]=='Q'){
      return false;
    }
  }

  //vertical safety
  for(int i=0;i<n;i++){
    if(board[i][col]=='Q'){
      return false;
    }
  }

  //diagonal safety
  //left diagoonal
  for(int i=row,j=col;i>=0 && j>=0 ;i--,j--){
    if(board[i][j]=='Q'){
      return false;
    }
  }

  //right diagonal
  for(int i=row,j=col;i>=0 && j<n;i--,j++){
    if(board[i][j]=='Q'){
      return false;
    }
  }
  return true;
}
void Nqueens(vector<vector<char>> board,int row){
  //base case;
  if(board.size()==row){
    print(board);
    return;
  }
   for(int j=0;j<board.size();j++){
        if(issafe(board,row,j)){
          board[row][j]='Q';
        Nqueens(board,row+1);
        board[row][j]='.';
        } 
   }
}

int main(){
  vector<vector<char>> board;
  int n=4;
  //creating board
  for(int i=0;i<n;i++){
    vector<char> temp;
    for(int j=0;j<n;j++){
      temp.push_back('.');
    }
    board.push_back(temp);
  }

  Nqueens(board,0);
  return 0;
}