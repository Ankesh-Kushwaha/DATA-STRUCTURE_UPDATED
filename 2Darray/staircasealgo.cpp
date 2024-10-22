#include <iostream>
using namespace std;

bool stair_case(int arr[][4],int n ,int m,int key){
     int row=0,numrow=4;
     int numcol=4,col=3;
     while(row<numrow && col>=0){
          if(arr[row][col]==key){
            return true;
          }
          if(arr[row][col]<key){
            row++;
          }
          else{
            col--;
          }
     }
     return false;
}
int main(){
  int arr[4][4]={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
  cout<<stair_case(arr,4,4,33)<<endl;
  return 0;
}
