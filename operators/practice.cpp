#include <iostream>
using namespace std;
int main(){
  // int x=2,y=5;
  // int exp1=(x*y/x);
  // int exp2=(x*(y/x));
  // cout<<exp1<<",";
  // cout<<exp2<<"\n";
  // int x=10 ,y=5;
  // int exp1=(y*(x/y+x/y));
  // int exp2=(y*x/y+y*x/y);
  // cout<<exp1<<" ";
  // cout<<exp2<<endl;
  int x=200,y=50,z=100;
  if(x>y && y>z){
    cout<<"Hello"<<endl;
  }
  if(z>y && z<x){
    cout<<" C++"<<endl;
  }
  if((y+200)<x && (y+150)<z){
    cout<<"Hello C++"<<endl;
  }
    return 0;
}