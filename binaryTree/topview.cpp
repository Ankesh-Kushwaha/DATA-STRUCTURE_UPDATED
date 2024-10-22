#include <iostream>
#include <queue>
#include<map>
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

void topView(Node* root){
   queue<pair<Node*,int>> Q;//Node,Horizontaldistance(HD)
   map<int,int> m;

   Q.push(make_pair(root,0));
   while(!Q.empty()){
    pair<Node*,int> curr=Q.front();
    Q.pop();

    Node* currNode=curr.first;
    int currHD=curr.second;
    
    if(m.count(currHD)==0){
      m[currHD]=currNode->data;
    }

    if(currNode->left!=NULL){
      pair<Node* ,int> left=make_pair(currNode->left,currHD-1);
      Q.push(left);
    }
    
    if(currNode->right!=NULL){
      pair<Node* ,int> right=make_pair(currNode->right,currHD+1);
      Q.push(right);
    }
   }

   for(auto it:m){
      cout<<it.second<<" ";
   }
   cout<<endl;

}

int main(){
vector<int> Nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root=buildTree(Nodes);
//levelorder(root);
topView(root);
  return 0;
}