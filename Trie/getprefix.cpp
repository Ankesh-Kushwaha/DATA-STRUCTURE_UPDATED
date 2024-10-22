#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Node{
public:
unordered_map<char,Node*> child;
int freq;
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
  root->freq=-1;
 }

 void insert(string key){
   Node* temp=root;
   for(int i=0;i<key.size();i++){
     if(temp->child.count(key[i])==0){
       temp->child[key[i]]=new Node();
       temp->child[key[i]]->freq=1;
     }
     else{
      temp->child[key[i]]->freq++;
     }
     temp=temp->child[key[i]];
     }
   temp->endOfline=true;
 }

 string getprefix(string key){
   Node* curr=root;
   string prefix="";
   for(int i=0;i<key.size();i++){
    prefix+=key[i];
    if(curr->child[key[i]]->freq==1){
      break;
    }else{
      curr=curr->child[key[i]];
    }
   }
   return prefix;
 }

};

void shortestprefix(vector<string> words){
   Trie tri;
   for(int i=0;i<words.size();i++){
    tri.insert(words[i]);
   }

   for(int i=0;i<words.size();i++){
    cout<<tri.getprefix(words[i])<<" ";
   }
   cout<<endl;
}

int main(){
  vector<string> words={"zebra","dog","duck","dove"};
  shortestprefix(words);
  return 0;
}