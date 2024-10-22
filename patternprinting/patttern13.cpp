#include <iostream>
using namespace std;
int main(){
  int n;
  cout<<"enter the number:"<<endl;
  cin>>n;
  int increment=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      cout<<increment<<" ";
      increment++;
    }
    cout<<endl;
  }
  return 0;
}