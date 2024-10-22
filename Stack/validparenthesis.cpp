#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
bool isValid(string str){
    stack<char> s;

    for(int i=0;i<str.size();i++){ //time complexity=O(n)
       char ch=str[i];
       //openning condition
       if(ch=='(' || ch=='{' || ch=='['){
           s.push(ch);
       }
       else{ //closing condition
        if(s.empty()){
           return false;
        }

        //matching
        char top=s.top();
        if((top=='(' && ch==')') ||
           (top=='{'&& ch=='}') ||
           (top=='[' && ch==']')){
              s.pop();
           }
           else{
            return false;
           }
       }
    }

    return s.empty(); //same as if(s.empty) true else false;
}
int main(){
  string str1="([}])"; //invalid
  string str2="([{}])";// valid;
  cout<<isValid(str1)<<endl;//0
  cout<<isValid(str2)<<endl;//1
  return 0;
}