#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

bool valid_anagram( string s,string t){
  if(s.size()!=t.size()){
    return false;
  }
unordered_map<char,int> freq;
//storing the value each character freq of string s;
for(int i=0;i<s.size();i++){
  if(freq.count(s[i])){
       freq[s[i]]++;
  }
  else{
    freq[s[i]]=1;
  }
}

//comparing the freq of t to s;
for(int i=0;i<t.size();i++){
   if(freq.count(t[i])){
      freq[t[i]]--;
      if(freq[t[i]]==0){
        freq.erase(t[i]);
      }
   }
   else{
    return false;
   }
}
 return freq.size()==0;
}

int main(){
string s="tulip";
string t="lipid";
cout<<valid_anagram(s,t)<<endl;
  return 0;
}