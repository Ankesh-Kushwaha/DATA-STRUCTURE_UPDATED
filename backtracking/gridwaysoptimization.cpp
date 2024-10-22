#include <iostream>
using namespace std;

int fact(int n){
  int factorial=1;
  for(int i=1;i<=n;i++){
    factorial*=i;
      }
      return factorial;
}
int main(){
  int n=3;
  int m=3;

  int ans=(fact(n-1+m-1))/(fact(n-1)*fact(m-1));
  cout<<ans<<endl;
  return 0;
}