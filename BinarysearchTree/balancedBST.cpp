#include <iostream>
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

Node* buildBST(int *arr,int st,int ed){
 //base case
 if(st>ed){
  return NULL;
 } 
 int mid=st+(ed-st)/2;
 Node* curr=new Node(arr[mid]);
 
 curr->left=buildBST(arr,st,mid-1);
 curr->right=buildBST(arr,mid+1,ed);
 return curr;
}

void preorder(Node* root){
  if(root==NULL){
    return ;
  }
  
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}
int main(){
  int arr[7]={3,4,5,6,7,8,9};
  Node* root=buildBST(arr,0,6);
  preorder(root);
  return 0;
}