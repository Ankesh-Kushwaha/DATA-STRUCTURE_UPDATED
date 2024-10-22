#include<iostream>
#include<vector>
#include<queue>
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

 Node* newnode=new Node(nodes[idx]); //allocating space to the new nodes;
 newnode->left=buildTree(nodes);
 newnode->right=buildTree(nodes);
 return newnode;
}

void preorder(Node* root){
  if(root==NULL){
    return ;
  }

  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node* root){
  if(root==NULL){
    return ;
  }

  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

void levelorder(Node*root){
  queue<Node*>q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    Node* curr=q.front();
    q.pop();
    
    if(curr==NULL){
      cout<<endl;
      if(q.empty()){
        break;
      }
      q.push(NULL); //for tracking of another line;
    }
    else{
      cout<<curr->data<<" ";
      if(curr->left!=NULL){
        q.push(curr->left);
      }

      if(curr->right!=NULL){
          q.push(curr->right);  
      }
    }
  }
}

int height(Node* root){
  if(root==NULL){
    return 0;
  }

  int leftHt=height(root->left);
  int rightHT=height(root->right);
  int currHt=max(leftHt,rightHT)+1;
  return currHt;
}





int main(){
  vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
  Node* root=buildTree(nodes);
  //preorder(root);
  //postorder(root);
  levelorder(root);
  cout<<"height of the tree is: "<<height(root)<<endl;
  return 0;
}