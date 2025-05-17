#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// create node of the tree
class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int data)
  {
    this->data = data;
    left = right = NULL;
  }
};

static int idx = -1;
Node *buildTree(vector<int> nums)
{
  idx++;
  if (nums[idx] == -1)
  {
    return NULL;
  }

  // create a new Node
  Node *newNode = new Node(nums[idx]);
  newNode->left = buildTree(nums);
  newNode->right = buildTree(nums);
  return newNode;
}

void preorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  cout << root->data << " ",
      preorder(root->left);
  preorder(root->right);
}

void inorder(Node *root)
{
  if (root == NULL)
    return;

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void postorder(Node *root)
{
  if (root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

void levelOrder(Node *root)
{
  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    int n = q.size();
    while (n--)
    {
      Node *curr = q.front();
      q.pop();
      cout << curr->data << " ";
      if (curr->left != NULL)
      {
        q.push(curr->left);
      }

      if (curr->right != NULL)
      {
        q.push(curr->right);
      }
    }
  }
}


int heightTree(Node*root){
      if(root==NULL)
        return 0;

      int leftHt = heightTree(root->left);
      int rightHt = heightTree(root->right);
      int currrHt = max(leftHt, rightHt) + 1;
      return currrHt;
}


int main()
{
  vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
  Node *root = buildTree(nodes);
  // cout << root->data << endl;
  cout << "preorder: ";
  preorder(root);
  cout << endl;
  cout << "inorder:" << " ";
  inorder(root);
  cout << endl;
  cout << "postorder:" << " ";
  postorder(root);
  cout << endl;
  cout << "inorder:" << " ";
  levelOrder(root);
  cout << endl;
  cout << "Height of the tree:" << heightTree(root) << endl;
  return 0;
}
