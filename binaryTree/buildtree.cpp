#include <iostream>
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
  //base case
  if(Nodes[idx]==-1){
    return NULL;
  }

  Node* currNode=new Node(Nodes[idx]);//6
  currNode->left=buildTree(Nodes);
  currNode->right=buildTree(Nodes);

  return currNode;
}

void preorder(Node* root){
  //base case
  if(root==NULL){
    return;
  }

   cout<<root->data<<endl;
   preorder(root->left);
   preorder(root->right);
}

void inorder(Node* root){
//base case
if(root==NULL){
  return ;
}

  inorder(root->left);//left sub-tree call
  cout<<root->data<<endl;//printing value of root
  inorder(root->right);//right sub-tree call
}

void postorder(Node* root){
  //base case
  if(root==NULL){
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<endl;
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

vector<int> levelorder2(Node*root){
  queue<Node*> q;
 
  vector<int> ans;
  q.push(root);
  while(!q.empty()){
    Node *curr = q.front();
    q.pop();

    ans.push_back(curr->data);

    if(curr->left){
      q.push(curr->left);
    }

    if(curr->right){
      q.push(curr->right);
    }

  }

  return ans;
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

int diameter(Node* root){
  if(root == NULL){
    return 0;
  }

  int currDia = height(root->left) + height(root->right) + 1;
  int leftDia = diameter(root->left);
  int rightDia = diameter(root->right);

  return max(currDia, max(leftDia, rightDia));
}


int main(){
vector<int> Nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root=buildTree(Nodes);
//cout<<"root:"<<root->data<<endl;

//preorder(root);
vector<int> temp=levelorder2(root);
for (int i = 0; i < temp.size();i++){
  cout << temp[i] << " ";
}

  // cout<<"Height of Tree is:"<<height(root)<<endl;
  // cout<<endl;
  // cout<<"diameter of the tree is :"<<diameter(root)<<endl;
  return 0;
}