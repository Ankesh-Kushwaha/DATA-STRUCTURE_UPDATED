#include <iostream>
using namespace std;
void printSudoko(int sudoko[9][9],int row,int col){
  cout<<endl;
  cout<<endl;
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cout<<sudoko[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  cout<<endl;
}

bool isSafe(int sudoko[9][9],int row,int col,int digit){
  //checking vertically downward
  for(int i=0;i<9;i++){
    if(sudoko[i][col]==digit){
      return false;
    }
  }

  //cheking horizontaly;
  for(int j=0;j<9;j++){
    if(sudoko[row][j]==digit){
      return false;
    }
  }

  //checking in the present grid;
  int startrow=(row/3)*3;
  int startcol=(col/3)*3;
  for(int i=startrow;i<=startrow+2;i++){
    for(int j=startcol;j<=startcol+2;j++){
      if(sudoko[i][j]==digit){
        return false;
      }
    }
  }

 return true;
}

bool sudokoSolver(int sudoko[9][9],int row,int col){
      //base case
      if(row==9){
        printSudoko(sudoko,row,col);
        return true;
      }

      int nextrow=row;
      int nextcol=col+1;
      if(col+1==9){
        nextrow=row+1;
        nextcol=0;
      }

      if(sudoko[row][col]!=0){
        return sudokoSolver(sudoko,nextrow,nextcol);
      }
     
     for(int i=1;i<=9;i++){
       if(isSafe(sudoko,row,col,i)){
          sudoko[row][col]=i;
          if(sudokoSolver(sudoko,nextrow,nextcol)){
            return true;
          }
          sudoko[row][col]=0;
       }
     }
     return false;
}

int main(){
  int sudoko[9][9]={{0,0,8,0,0,0,0,0,0},
                    {4,9,0,1,5,7,0,0,2},
                    {0,0,3,0,0,4,1,9,0},
                    {1,8,5,0,6,0,0,2,0},
                    {0,0,0,0,2,0,0,6,0},
                    {9,6,0,4,0,5,3,0,0},
                    {0,3,0,0,7,2,0,0,4},
                    {0,4,9,0,3,0,0,5,7},
                    {8,2,7,0,0,9,0,1,3}
                    };

   cout<<sudokoSolver(sudoko,0,0);                 
  return 0;
}