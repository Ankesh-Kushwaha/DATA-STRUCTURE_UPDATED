#include <iostream>
using namespace std;
int main(){
string s;
cin>>s;
int cnt=0;
for(int i=0;i<s.length();i++){
  cnt++;
}
  if(cnt>=10){
    cout<<s[0]<<cnt-2<<s[s.length()-1];
  }
  else{
    cout<<s;
  }

  return 0;
}