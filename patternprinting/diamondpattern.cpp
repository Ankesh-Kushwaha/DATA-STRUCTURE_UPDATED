#include <iostream>
using namespace std;
int main(){
  int n;
  cout<<"enter the number:"<<endl;
  cin>>n;
  cout<<endl;
  for(int i=1;i<=n;i++){
     //space;
     for(int k=1;k<=n-i;k++){
      cout<<" ";
     }
    for(int j=1;j<=2*i-1;j++){
      cout<<"*";
    }
   
    cout<<endl;
  }

  //second half of pyramid
  for(int i=1;i<=n;i++){
    //spaces;
    for(int k=1;k<=i-1;k++){
      cout<<" ";
    }
    for(int j=0;j<=n-i;j++){
      cout<<"*";
    }
    for(int l=1;l<=n-i;l++){
      cout<<"*";
    }
    cout<<endl;
  }
  cout<<endl;
  return 0;
}