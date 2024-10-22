#include <iostream>
#include <vector>
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

void Kthhelper(Node* root,int k,int currlevel){
 //base case
 if(root==NULL){
  return ;
 }

  if(k==currlevel){
    cout<<root->data<<" ";
    return ;
  }

  Kthhelper(root->left,k,currlevel+1);
  Kthhelper(root->right,k,currlevel+1);
}

void Kthlevel(Node* root,int k){
    Kthhelper(root,k,1);
    cout<<endl;
}
int main(){
vector<int> Nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root=buildTree(Nodes);
int k=3;
Kthlevel(root,k);
  return 0;
}