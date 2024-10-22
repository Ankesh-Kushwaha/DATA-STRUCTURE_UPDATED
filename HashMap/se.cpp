#include <iostream>
#include<unordered_set>
#include<set>
using namespace std;
int main(){
set<int> s;
for(int i=0;i<5;i++){
  s.insert(i);
}

for(int i=0;i<5;i++){
  s.insert(i);
}

//s.erase(3);
if(s.find(2)!=s.end()){
  cout<<"2 exist"<<endl;
}
else{
  cout<<"2 doesn't exist"<<endl;
}
cout<<s.size()<<endl;
for(auto &p :s){
  cout<<p<<endl;
}
return 0;
}