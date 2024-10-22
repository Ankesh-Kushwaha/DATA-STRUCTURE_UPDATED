#include <iostream>
using namespace std;
int main(){
  int n;
  cout<<"enter the number:"<<endl;
  cin>>n;
  for(int i=1;i<=n;i++){
     cout<<"*";
     for(int j=1;j<=n-1;j++){
      if(i==1 || i==n){
        cout<<"*";
      }
      else{
        cout<<" ";
      }
     }
     cout<<"*";
     cout<<endl;
  }
  return 0;
}