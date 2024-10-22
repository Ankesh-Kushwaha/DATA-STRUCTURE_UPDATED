#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
unordered_map<string,int> m;
m["india"]=789;
m["chna"]=783;
m["USA"]=56;
m["Nepal"]=775;

m.erase("india");
for(pair<string,int> country:m){
  cout<<country.first<<" : "<<country.second<<endl;
}

if(m.count("India")){
  cout<<"INdia exist"<<endl;
}
else{
  cout<<"India doesn't exist"<<endl;
}

  return 0;
}