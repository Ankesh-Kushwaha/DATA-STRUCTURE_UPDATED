#include <iostream>
using namespace std;
void diagonal_sum(int arr[][4],int n){  //time complexity ->O(N^2);
  int sum=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j){
        sum+=arr[i][j];  //primary diagonal sum;
      }
      else if(j==n-i-1){
        sum+=arr[i][j];  //secondary diagonal sum;
      }
    }
  }
   cout<<"sum of diagonal is:"<<sum<<endl;
}

void diagonal_sum2(int arr[][4],int n ){   //time complexity -> O(N); 
  int sum=0;                               //optimised solution;
    for(int i=0;i<n;i++){
       sum+=arr[i][i]; //primary diagonal sum;
       if(i!=n-i-1){
         sum+=arr[i][n-i-1];
       }
    }
     cout<<"sum of diagonal is:"<<sum<<endl;
}

int main(){
  int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  diagonal_sum2(arr,4);
  return 0;
}