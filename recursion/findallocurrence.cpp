#include <iostream>
#include<vector>
using namespace std;

void search(int *arr,int n,int key,vector<int> &ans){

  //base case
  if(n==0){
    for(int i=ans.size()-1;i>=0;i--){
      cout<<ans[i]<<" ";
    }
    cout<<endl;
    return ;
  }  

 
  //processing
  if(arr[n]==key){
    ans.push_back(n);
  }

//recursive call
  search(arr,n-1,key,ans);
}
int main(){
  vector<int>ans;
  int arr[9]={3,2,4,5,6,2,7,2,2};
  search(arr,8,2,ans);
  return 0;
}