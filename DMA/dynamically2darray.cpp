#include <iostream>
using namespace std;
int main(){
  int row,col;
  cout<<"enter row:"<<endl;
  cin>>row;
  cout<<"enter col:"<<endl;
  cin>>col;

  //allocating memory for 2D-array;
  int **matrix=new int*[row];
  for(int i=0;i<row;i++){
    matrix[i]=new int[col];
  }
  
  //data storing;
  int x=1;
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      matrix[i][j]=x++;
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<matrix[2][2]<<endl;
  cout<<*(*(matrix+2)+2);
   delete[] matrix;
  return 0;
}