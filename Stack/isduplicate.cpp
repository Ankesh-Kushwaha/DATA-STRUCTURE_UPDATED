#include <iostream>
#include<stack>
#include<string>
using namespace std;

bool isDuplicate(string str){
   stack<char>s;
  for(int i=0;i<str.size();i++){
     char ch=str[i];
     if(ch!=')'){ //non-closing
       s.push(ch);
     }
     else{ //closing 
        if(s.top()=='('){
          return true; //duplicate
        }
        
        while(s.top()!='('){
          s.pop();
        }
        s.pop();
     }
  }
  return false;
}

int main(){
  string str="((a+b))";//duplicate present->true;
  string str1="((a+b)+(c+d))";//duplicate not present -> false;
  
  cout<<isDuplicate(str)<<endl;
  cout<<isDuplicate(str1)<<endl;
  return 0;
}