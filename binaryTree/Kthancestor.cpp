#include <iostream>
#include<vector>
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

int KthAncestor(Node* root,int node,int K){
      //base case
      if(root==NULL){
        return -1;
      }

      if(root->data==node){
        return 0;
      }

      int leftdis=KthAncestor(root->left,node,K);
      int rightdis=KthAncestor(root->right,node,K);
      if(leftdis==-1 && rightdis==-1){
        return -1;
      }

      int validValue=leftdis==-1 ? rightdis : leftdis;
      if(validValue+1==K){
        cout<<"required Kth Ancestor is:"<<root->data<<endl;
      }
      return validValue+1;
}

int main(){
 vector<int> Nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
 Node* root=buildTree(Nodes);
 
 int node=4,K=1;
 KthAncestor(root,node,K);
  return 0;
}