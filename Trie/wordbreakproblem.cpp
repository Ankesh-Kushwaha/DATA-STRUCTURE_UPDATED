#include<iostream>
#include <unordered_map>
#include<string>
#include<vector>
using namespace std;

class Node{
public:
unordered_map<char,Node*> child;
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
    if(temp->child.count(key[i])==0){
       temp->child[key[i]]=new Node();
    }
    temp=temp->child[key[i]];
  }

  temp->endOfline=true;
}

bool search(string key){
  Node* temp=root;
  for(int i=0;i<key.size();i++){
    if(temp->child.count(key[i])){
      temp=temp->child[key[i]];
    }
    else{
      return false;
    }
  }
  return temp->endOfline;
}
};

bool helper(Trie &tri,string key){
  if(key.size()==0){
    return true;
  }
    for(int i=0;i<key.size();i++){
       string first=key.substr(0,i+1);
       string second=key.substr(i+1);
       if(tri.search(first) && helper(tri,second)){
        return true;
       }
    }
    return false;
}
bool wordBreak(vector<string> dic,string key){
   Trie tri;
   for(int i=0;i<dic.size();i++){
    tri.insert(dic[i]);
   }

   return helper(tri,key);
}

int main(){
vector<string> dic={"i","like","sam","samsung","mobile","ice"};
cout<<wordBreak(dic,"ilikesamsung")<<endl;
cout<<wordBreak(dic,"mobileice")<<endl;

  return 0;
}