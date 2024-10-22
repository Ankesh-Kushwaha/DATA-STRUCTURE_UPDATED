#include <iostream>
#include<string>
using namespace std;

void printsubset(string str,string subset){
  
  if(str.size()==0){
    cout<<subset<<endl;
    return; //bactrack
  }

  char ch=str[0];

  //yes choice
  printsubset(str.substr(1,str.size()-1),subset+ch);

  //no choice
  printsubset(str.substr(1,str.size()-1),subset);

}


int main(){
  string str="abc";
  string subset="";
  printsubset(str,subset);
  return 0;
}