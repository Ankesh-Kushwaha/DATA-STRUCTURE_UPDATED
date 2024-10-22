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
Node* buildTree(vector<int>Nodes){
   idx++;
   //base case 
   if(Nodes[idx]==-1){
    return NULL;
   }

   //creating a current node
   Node* currNode=new Node(Nodes[idx]);
   currNode->left=buildTree(Nodes);
   currNode->right=buildTree(Nodes);

   return currNode;
}

bool findPath(Node* root,int n,vector<int> &path){
    
    //base case
    if(root==NULL){
      return false;
    }

    path.push_back(root->data);
    if(root->data==n){
      return true;
    }
    int leftpart=findPath(root->left,n,path);
    int rightpart=findPath(root->right,n,path);

    if(leftpart || rightpart){
      return true;
    }
    path.pop_back();
    return false;
} 

int LCA(Node* root,int n1,int n2){
    vector<int>path1;
    vector<int>path2;
    
    findPath(root,n1,path1);
    findPath(root,n2,path2);
    
    int lca=-1;
    for(int i=0 ,j=0;i<path1.size() && j<path2.size();i++,j++){
       if(path1[i]!=path2[j]){
           return lca;
       }
       lca=path1[i];
    }
  return lca;
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

int main(){
vector<int> Nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root=buildTree(Nodes);
cout<<"lca is:"<<LCA2(root,4,6)->data<<endl;
  return 0;
}