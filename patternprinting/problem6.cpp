#include <iostream>
using namespace std;
int main(){
  for(int i=0;i<5;i++){
    for(int j=0;j<5-i;j++){ //for spacing 
      cout<<" ";
    }
    for(int k=0;k<=i;k++){ //for second part
      cout<<"*";
    }
     for(int l=1;l<=i;l++){ //for third part
      cout<<"*";
     }
    cout<<endl;
  }
  return 0;
}