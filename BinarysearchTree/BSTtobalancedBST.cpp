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

Node* insert(Node* root,int val){
  if(root==NULL){
    root=new Node(val);
    return root;
  }

  if(val>root->data){
    root->right=insert(root->right,val);
  }
  else{
    root->left=insert(root->left,val);
  }
  return root;
}

Node* buildTree(Node* root,vector<int> &arr){
 root=NULL;
 for(int i=0;i<arr.size();i++){
      root=insert(root,arr[i]);
 }
 return root;
}

Node* buildBSTbalanced(vector<int> &arr,int st,int ed){
 //base case
 if(st>ed){
  return NULL;
 } 
 int mid=st+(ed-st)/2;
 Node* curr=new Node(arr[mid]);
 
 curr->left=buildBSTbalanced(arr,st,mid-1);
 curr->right=buildBSTbalanced(arr,mid+1,ed);
 return curr;
}

void inorder(Node* root,vector<int> &sorted){
  if(root==NULL){
    return ;
  }
  
  inorder(root->left,sorted);
  sorted.push_back(root->data);
  inorder(root->right,sorted);
}

void preorder(Node* newroot){
   if(newroot==NULL){
    return;
   }

   cout<<newroot->data<<" ";
   preorder(newroot->left);
   preorder(newroot->right);
}
int main(){
  vector<int> arr={6,5,4,3,7,8,9};
  Node* root=buildTree(root,arr);
  vector<int>sorted;
  inorder(root,sorted);
  Node* newroot=buildBSTbalanced(sorted,0,sorted.size()-1);
  preorder(newroot);
  return 0;
}