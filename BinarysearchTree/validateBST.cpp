#include<iostream>
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

Node* buildTree(Node* root,int* arr){
   root=NULL;
for(int i=0;i<9;i++){
  root=insert(root,arr[i]);
}
return root;
}

void inorder(Node* root){
  if(root==NULL){
    return ;
  }

  inorder(root->left);
   cout<<root->data<<" ";
  inorder(root->right);
}


bool validateBSThelper(Node* root,Node* min,Node* max){
 if(root==NULL){
  return true;
 }

 if(min!=NULL && root->data<min->data){
   return false;
 }
 if(max!=NULL && root->data>max->data){
  return false;
 }

 return validateBSThelper(root->left,min,root) &&
         validateBSThelper(root->right,root,max);
}

bool validateBST(Node* root){
  return validateBSThelper(root,NULL,NULL);
}

int main(){
int arr[9]={8,5,3,1,4,6,10,11,14};
Node* root=buildTree(root,arr);
inorder(root);
cout<<endl;
root->data=15;
cout<<validateBST(root)<<endl;
  return 0;
}