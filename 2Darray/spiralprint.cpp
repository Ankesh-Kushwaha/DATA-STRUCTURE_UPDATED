#include <iostream>
using namespace std;

void spiral_print(int arr[][4],int n,int m){
       int srow=0;
       int scol=0;
       int erow=m-1;
       int ecol=n-1;

   while(srow<=erow && scol<=ecol){
     
       //printing top;
       for(int i=scol;i<=ecol;i++){
        cout<<arr[srow][i]<<" ";
       }
       
       //printing right;
       for(int i=srow+1;i<=erow;i++){
        cout<<arr[i][ecol]<<" ";
       }

       //printing bottom;
      if(srow<erow){ for(int i=ecol-1;i>=scol;i--){
         cout<<arr[erow][i]<<" ";
       }}

       //printing left
       if(scol<ecol){for(int i=erow-1;i>srow;i--){
          cout<<arr[i][scol]<<" ";
       }}

       srow++;
       erow--;
       scol++;
       ecol--;

    }
}

int main(){
  int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  spiral_print(arr,4,4);
  return 0;
}