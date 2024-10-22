#include<iostream>
#include<vector>
#include<queue>
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
Node* buildTree(vector<int> node){
  idx++;
    if(node[idx]==-1){
      return NULL;
    }

    Node* currNode=new Node(node[idx]);
    currNode->left=buildTree(node);
    currNode->right=buildTree(node);
    return currNode;
}

void levelOrder(Node* root,vector<int> &ans){ 
  if(root==NULL){
    return;
  }

  int num=0;
  queue<Node*> Q;
  Q.push(root);
  Q.push(NULL);
  while(!Q.empty()){
       Node* curr=Q.front();
       Q.pop();
       if(curr==NULL){
         ans.push_back(num);
         num=0;
        cout<<endl;
        if(Q.empty()){
          break;
        }
       
        Q.push(NULL);
       }
       else{
         cout<<curr->data<<" ";
         num+=curr->data;
         if(curr->left!=NULL){
           Q.push(curr->left);
         }

         if(curr->right!=NULL){
             Q.push(curr->right);
         }
       }
  }
}

int main(){
  vector<int> nodes={5,8,2,4,-1,-1,6,-1,-1,1,-1,-1,9,3,-1,-1,7,-1,-1};
  Node* root=buildTree(nodes);
  vector<int> ans;
  levelOrder(root,ans);

  for(int i=0;i<ans.size();i++){
     cout<<ans[i]<<" ";
  }
  cout<<ans[2]<<endl;

  return 0;
}