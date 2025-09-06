#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
  public:
  int val;
  Node *left;
  Node *right;
  Node(int val){
    this->val = val;
    left = NULL;
    right = NULL;
  }
};

static int idx = -1;
Node* buildTree(vector<int> &arr){
  idx++;
  if(arr[idx]==-1){
    return NULL;
  }

  Node *newNode = new Node(arr[idx]);
  newNode->left = buildTree(arr);
  newNode->right = buildTree(arr);
  return newNode;
}

int findMaxPathSum(Node* root,int &finalPath){
     if(root==NULL)
       return 0;

     int leftPath = max(0, findMaxPathSum(root->left,finalPath));
     int rightPath = max(0, findMaxPathSum(root->right,finalPath));

     int currPath = root->val + leftPath + rightPath;
     finalPath = max(finalPath, currPath);

     return root->val + max(leftPath, rightPath);
}

int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n;i++){
    cin >> arr[i];
  }

  Node *root = buildTree(arr);
  int finalPath = 0;
  findMaxPathSum(root, finalPath);
  cout << "final Path:" << finalPath << endl;
  return 0;
}