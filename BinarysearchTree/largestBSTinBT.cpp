#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* left;
  Node* right;
  //constructor
  Node(int data){
    this->data=data;
    left=right=NULL;
  }
};

class Info{
 public:
   bool isBST;
   int min;
   int max;
   int sz; 
  //constructor
  Info(bool isBST,int min,int max,int sz){
     this->isBST=isBST;
     this->min=min;
     this->max=max;
     this->sz=sz;
       }
  };

  static int maxSize;
  Info* largestBST(Node* root){
    //base case
    if(root==NULL){
       return new Info(true,INT32_MAX,INT32_MIN,0);
    }
    Info* leftInfo=largestBST(root->left);
    Info* rightInfo=largestBST(root->right);

    int currMin=min(root->data, min(leftInfo->min,rightInfo->min));
    int currMax=max(root->data, max(leftInfo->max,rightInfo->max));
    int currsiz=leftInfo->sz + rightInfo->sz+1;

    if((leftInfo->isBST && rightInfo->isBST)&&
        (root->data>leftInfo->max) && (root->data<rightInfo->min) ){
        maxSize=currsiz;
        return new Info(true,currMin,currMax,currsiz);
    }

    return new Info(false,currMin,currMax,currsiz);
  }

int main(){
Node*root=new Node(50);
root->left=new Node(30);
root->left->left=new Node(5);
root->left->right=new Node(20);

root->right=new Node(60);
root->right->left=new Node(45);
root->right->right=new Node(70);
root->right->right->left=new Node(65);
root->right->right->right=new Node(80);

largestBST(root);
cout<<"max size:"<<maxSize<<endl;

  return 0;
}