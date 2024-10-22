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

int countNodes(Node* node) {
            if (!node) return 0;
            int count = 1; // Count the current node
            for (auto& child : node->children) {
                count += countNodes(child.second);
            }
            return count;
        }

  int countNodes(){
    return countNodes(root);
  }
};

int findSuffix(string key){
  Trie trie;
   for(int i=0;i<key.size();i++){
      trie.insert(key.substr(i));
   }

  int ans=trie.countNodes();
  return ans+1; 
}

int main(){
vector<string> words={"apple","app","apply"};
for(int i=0;i<words.size();i++){
  cout<<findSuffix(words[i])<<endl;
}

  return 0;
}