#include <iostream>
#include<queue>
#include<string>
using namespace std;
void firstNonRepeated(string str){
   queue<char>Q;
   int freq[26]={0};

   for(int i=0;i<str.length();i++){
     char ch=str[i];
     Q.push(ch);
     freq[ch-'a']++;

     while(!Q.empty() && freq[Q.front()-'a']>1){
       Q.pop();
     }

     if(Q.empty()){
      cout<<"-1"<<endl;
     }
     else{
      cout<<Q.front()<<endl;
     }
   }
}

int main(){
string str="aabccxb";
firstNonRepeated(str);
  return 0;
}