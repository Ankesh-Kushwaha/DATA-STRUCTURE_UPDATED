#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
map<string,int> m;
m["india"]=789;
m["china"]=783;
m["usa"]=56;
m["nepal"]=775;

//m.erase("india");
for(pair<string,int> country:m){
  cout<<country.first<<" : "<<country.second<<endl;
}

if(m.count("india")){
  cout<<"INdia exist"<<endl;
}
else{
  cout<<"India doesn't exist"<<endl;
}

  return 0;
}