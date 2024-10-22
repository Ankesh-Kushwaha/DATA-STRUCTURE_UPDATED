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

int height(Node* root){
  if(root==NULL){
    return 0;
  }
  int leftHt=height(root->left);
  int rightHt=height(root->right);
  int currHt=max(leftHt,rightHt)+1;
  return currHt;
}


void levelorder(Node* root){
  if(root==NULL){
    return ;
  }

  queue<Node*>Q;
  Q.push(root);
  Q.push(NULL);

  while(!Q.empty()){
    Node* curr=Q.front();
    Q.pop();

    if(curr==NULL){
      cout<<endl;
      if(Q.empty()){
        break;
      }
      Q.push(NULL);// to track the next line;
    }
    else{
     
    cout<<curr->data<<" ";
  
    if(curr->left!=NULL){
      Q.push(curr->left);
    }
    if(curr->right!=NULL){
      Q.push(curr->right);
    }
    }
    }
}

int sum(Node* root){
  if(root==NULL){
    return 0;
  }
  int left_sum=sum(root->left);
  int right_sum=sum(root->right);
  
  int curr_sum= left_sum+right_sum+root->data;
  cout<<"sum :"<<curr_sum<<endl;
  return curr_sum;
}

int countNode(Node* root){
 //base case
 if(root==NULL){
     return 0;
 }
int leftNode=countNode(root->left);
int rightNode=countNode(root->right);
return leftNode+rightNode+1;
}

int main(){
vector<int> Nodes={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
Node* root=buildTree(Nodes);
levelorder(root);
cout<<"height of binary Tree is:"<<height(root)<<endl;
cout<<"no of Nodes:"<<countNode(root)<<endl;
cout<<"sum of the tree is:"<<sum(root)<<endl;
  return 0;
}