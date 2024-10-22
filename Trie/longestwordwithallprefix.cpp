#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
class Node{
public:
unordered_map<char,Node*>children;
bool endOfline;
Node(){
  endOfline=false;
}
};

class Trie{
  Node* root;
 public:
 Trie(){
  root=new Node();
 } 

 void insert(string key){
  Node* temp=root;
  for(int i=0;i<key.size();i++){
    if(temp->children.count(key[i])==0){
      temp->children[key[i]]=new Node();
    }
    temp=temp->children[key[i]];
  }
  temp->endOfline=true;
 }

void longestHelper(Node* root,string &ans,string temp){
  for(pair<char,Node*> child:root->children){
    if(child.second->endOfline){
       temp+=child.first;

       if((temp.size()==ans.size() && temp<ans) || (temp.size()>ans.size())){
        ans=temp;
       }

       longestHelper(child.second,ans,temp);
       temp=temp.substr(0,temp.size()-1);
    }
  }
}

string longeststrwithEOL(){
  string ans="";
  longestHelper(root,ans,"");
  return ans;
}
};

string longeststr(vector<string> words){
  Trie trie;
 for(int i=0;i<words.size();i++){
   trie.insert(words[i]);
 }
 return trie.longeststrwithEOL();
}
int main(){
vector<string> words={"a","banana","app","appl","ap","apply"};
cout<<longeststr(words)<<endl;
  return 0;
}