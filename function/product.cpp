#include <iostream>
using namespace std;

int prod(int n,int m){
  return n*m;
}
int main(){
  int a,b;
  cout<<"enter the values to multiply"<<endl;
  cin>>a>>b;
  int ans=prod(a,b);
  cout<<ans<<endl;
}
