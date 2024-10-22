#include <iostream>
#include <vector>
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

void getinorder(Node* root,vector<int> &nodes){
   if(root==NULL){
    return ;
   }

   getinorder(root->left,nodes);
   nodes.push_back(root->data);
   getinorder(root->right,nodes);
}

Node* mergeBSTsorted(vector<int> merge,int st,int ed){
  if(st>ed){
    return NULL;
  }
  int mid=st+(ed-st)/2;
  Node* curr=new Node(merge[mid]);
  curr->left=mergeBSTsorted(merge,st,mid-1);
  curr->right=mergeBSTsorted(merge,mid+1,ed);
  return curr;
}
Node* mergeBST(Node* root1,Node* root2){
  vector<int> nodes1;
  vector<int> nodes2;
  vector<int> merge;
  
  getinorder(root1,nodes1);
  getinorder(root2,nodes2);

  //merging two nodes
  int i=0;int j=0;
  while(i<nodes1.size() && j<nodes2.size()){
     if(nodes1[i]<nodes2[j]){
      merge.push_back(nodes1[i++]);
     }
     else{
       merge.push_back(nodes2[j++]);
     }
  }
   //appending remaining element;
    while(i<nodes1.size()){
      merge.push_back(nodes1[i++]);
     }
     while(j<nodes2.size()){
      merge.push_back(nodes2[j++]);
     }

  return mergeBSTsorted(merge,0,merge.size()-1);
}

void getpreorder(Node* root){
  if(root==NULL){
    return;
  }

  cout<<root->data<<" ";
  getpreorder(root->left);
  getpreorder(root->right);
}

int main(){
  Node* root1=new Node(2);
  root1->left=new Node(1);
  root1->right=new Node(4);

  Node* root2=new Node(9);
  root2->left=new Node(3);
  root2->right=new Node(12);

 Node* root=mergeBST(root1,root2);
 getpreorder(root);
  return 0;
}