#include <iostream>
using namespace std;
int main(){
  int a,b,c;
  cout<<"enter the three numbers to compare"<<endl;
  cin>>a>>b>>c;
  if(a>=b && a>=c){
    cout<<a<<" is greatest"<<endl;
  }
  else if(b>a && b>c){
    cout<<b<<" is gratest"<<endl;
  }
  else {
    cout<<c<<" is greatest";
  }
  return 0;
}