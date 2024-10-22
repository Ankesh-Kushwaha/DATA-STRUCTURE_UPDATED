#include <iostream>
using namespace std;
int main(){
  int n;
  cout<<"enter the number"<<endl;
  cin>>n;
  int space=2*(n-1);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      cout<<j;
    }
    //for spacing
    for(int l=1;l<=space;l++){
      cout<<" ";
    }
    for(int k=i;k>=1;k--){
      cout<<k;
    }
    cout<<endl;
    space-=2;
  }
  return 0;
}