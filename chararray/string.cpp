#include <iostream>
#include<string>
using namespace std;
int main(){
 string str;
 getline(cin,str); //taking input strings
//  cout<<str.length()<<endl;
//  cout<<str<<endl;

//for each loop
for(char ch:str){
    cout<<ch<<" "<<endl;
}
  return 0;
}