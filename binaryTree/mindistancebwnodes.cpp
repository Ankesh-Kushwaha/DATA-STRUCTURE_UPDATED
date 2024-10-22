#include<iostream>
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


Node* LCA2(Node* root,int n1,int n2){
 //base case 
 if(root==NULL){
  return root;
 }

  if(root->data==n1 || root->data==n2){
    return root;
  }

  Node* leftLCA=LCA2(root->left,n1,n2);
  Node* rightLCA=LCA2(root->right,n1,n2);

  if(leftLCA!=NULL && rightLCA!=NULL){
    return root;
  }

  return leftLCA==NULL?rightLCA:leftLCA;
}


int mindis(Node* lca,int n){
  //base case
 if(lca==NULL){
  return -1;
 }

 if(lca->data==n){
  return 0;
 }
 int leftdis=mindis(lca->left,n);
 if(leftdis!=-1){
  return leftdis+1;
 }

 int rightdis=mindis(lca->right,n);
 if(rightdis!=-1){
  return rightdis+1;
 }
 return -1;
}

int minDistance(Node*root,int n1,int n2){
  Node* lca=LCA2(root,n1,n2);
  int dis1=mindis(lca,n1);
  int dis2=mindis(lca,n2);
  return dis1+dis2;
}

int main(){
 vector<int> Nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
 Node* root=buildTree(Nodes);
//traversal(root);
int n1=4,n2=6;
cout<<"minimum Distance:"<<minDistance(root,n1,n2)<<endl;
return 0;
}