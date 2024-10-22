#include <iostream>
using namespace std;
class Node{
  public:
   int data;
   Node* left;
   Node* right;

   //constructur
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

Node* buildBST(int *arr,int n){
  Node* root=NULL;
  for(int i=0;i<n;i++){
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

bool search(Node* root,int key){
   //base case;
   if(root==NULL){
    return false;
   }

   if(root->data==key){
    return true;  //key found;
   }

   if(root->data>key){
      return search(root->left,key);
   }
   else{
    return search(root->right,key);
   }
}

int main(){
//int arr[6]={5,1,3,4,2,7};
int arr[9]={8,5,3,1,4,6,10,11,14};
Node* root=buildBST(arr,9);
inorder(root);
cout<<endl;
cout<<search(root,100)<<endl;
  return 0;
}