#include <iostream>
#include<map>
using namespace std;
int main(){
  map<int,string> m;
  m[101]="Ankesh";
  m[110]="rahul";
  m[131]="aditya";
  m[101]="kushwaa"; //it replace the previous value;

  // cout<<m[101]<<endl;
  // cout<<m[564]<<endl;
  // cout<<m.count(101)<<endl;
  // cout<<m.count(125)<<endl;

  for(auto it:m){
    cout<<"| key :"<<it.first<<" value: "<<it.second;  }
return 0;
}