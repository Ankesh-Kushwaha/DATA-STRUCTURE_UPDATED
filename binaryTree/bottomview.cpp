#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;
class Node{
 public:
 int data;
 Node* left;
 Node* right;

 Node(int data){
  this->data=data;
  left=right=NULL;
 }
};

static int idx=-1;
Node* buildTree(vector<int> nodes){
 idx++;
 if(nodes[idx]==-1){
  return NULL;
 }

 Node* newNode=new Node(nodes[idx]);
 newNode->left=buildTree(nodes);
 newNode->right=buildTree(nodes);
 return newNode;
}

void bottomView(Node* root){
 queue<pair<Node*,int>> q; //to store the value of node and its horizontal distance;
 map<int,int> m;// to store the value of currNode and its HD;(key->HD,value->currNode->data);
 
 q.push(make_pair(root,0));
 
 while(!q.empty()){
  pair<Node*,int> curr=q.front();
  q.pop();
  Node* currNode=curr.first;
  int HD=curr.second;

  if(m.count(HD)==0){
    m[HD]=currNode->data;
  }
  else{
    m[HD]=currNode->data;//updation of the value if it present already
  }

  if(currNode->left!=NULL){
    pair<Node*,int> left=make_pair(currNode->left,HD-1);
    q.push(left);
  }
  
  if(currNode->right!=NULL){
    pair<Node*,int> right=make_pair(currNode->right,HD+1);
    q.push(right);
  }
 }

 for(auto it:m){
  cout<<it.second<<" ";
 }
 cout<<endl;
}
int main(){
vector<int> nodes={20,8,5,-1,-1,3,10,-1,-1,-1,22,4,-1,14,-1,-1,25,-1,-1};
Node* root=buildTree(nodes);
bottomView(root);
  return 0;
}