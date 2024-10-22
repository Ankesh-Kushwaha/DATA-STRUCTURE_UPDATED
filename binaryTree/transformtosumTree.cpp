#include <iostream>
#include<vector>
#include<queue>
using namespace std;


class Node{
public:
int data;
Node* left;
Node* right;
//constructor;
Node(int data){
  this->data=data;
  left=right=NULL;
}
};

static int idx=-1;
Node* buildTree(vector<int> Nodes){
  idx++;
  if(Nodes[idx]==-1){
    return NULL;
  }

  Node* currNode=new Node(Nodes[idx]);
  currNode->left=buildTree(Nodes);
  currNode->right=buildTree(Nodes);
  return currNode;
}


void traversal(Node* root){
 //base case
 if(root==NULL){
  return ;
 }

 queue<Node*> Q;
 Q.push(root);
 Q.push(NULL);
 while(!Q.empty()){
    Node* curr=Q.front();
    Q.pop();

    if(curr==NULL){
      cout<<endl;
      if(Q.empty()){
        break;
      }
      Q.push(NULL);
    }
    else{
      cout<<curr->data<<" ";
      if(curr->left!=NULL){
        Q.push(curr->left);
      }

      if(curr->right!=NULL){
        Q.push(curr->right);
      }
    }
 }
}

int transform(Node* root){
  //base case 
  if(root==NULL){
    return 0;
  }

  int leftOld=transform(root->left);
  int rightOld=transform(root->right);
  int currOld=root->data;

  root->data=leftOld+rightOld;
  if(root->left!=NULL){
    root->data+=root->left->data;
  }
  if(root->right!=NULL){
    root->data+=root->right->data;
  }
 return currOld;
}

int main(){
vector<int> Nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
 Node* root=buildTree(Nodes);
 traversal(root);
 transform(root);
 traversal(root);
 cout<<89+NULL<<endl;
  return 0;
}