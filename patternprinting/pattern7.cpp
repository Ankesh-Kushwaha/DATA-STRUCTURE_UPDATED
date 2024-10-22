#include <iostream>
using namespace std;
int main(){
  for(int i=0;i<5;i++){
    for(int j=1;j<=i;j++){
      cout<<" ";
    }
    for(int k=0;k<5-i;k++){
      cout<<"*";
    }
    for(int l=1;l<5-i;l++){
      cout<<"*";
    }
    cout<<endl;
  }
  return 0;
}