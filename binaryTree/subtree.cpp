#include<iostream>
#include<vector>
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

void postorder(Node* root) {
    // base case
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " "; // Print after left and right children
}

bool is_identical(Node* root1,Node*root2){
   //base case
   if(root1==NULL && root2==NULL){
    return true;
   }
   else if(root1==NULL || root2==NULL){
      return false;
    
   }
   if(root1->data!=root2->data){
    return false;
   }
   return is_identical(root1->left,root2->left)&&
          is_identical(root1->right,root2->right);
}


bool is_subTree(Node* root,Node* subroot){
  //base case
  if(root==NULL && subroot==NULL){
    return true;
  }
  else  if(root==NULL || subroot==NULL){
      return false;
  }

   if(root->data==subroot->data){
    if(is_identical(root,subroot)){
      return true;
    }
   }

   int leftsubtree=is_subTree(root->left,subroot);
   if(!leftsubtree){
         return is_subTree(root->right,subroot);
   }
   return true;
}

int main(){
vector<int> Nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root=buildTree(Nodes);

Node* subroot=new Node(2);
subroot->left=new Node(4);
subroot->right=new Node(5);

cout<<is_subTree(root,subroot)<<endl;
  return 0;
}