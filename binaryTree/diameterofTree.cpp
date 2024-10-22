#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    //constructor
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* buildTree(vector<int>& nodes, int& idx) {
    if (idx >= nodes.size() || nodes[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* currNode = new Node(nodes[idx++]);
    currNode->left = buildTree(nodes, idx);
    currNode->right = buildTree(nodes, idx);
    return currNode;
}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    int currHt = max(leftHt, rightHt) + 1;
    return currHt;
}

int diameter(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int currDia = height(root->left) + height(root->right) + 1;
    int leftDia = diameter(root->left);
    int rightDia = diameter(root->right);

    return max(currDia, max(leftDia, rightDia));
}

pair<int,int> diam2(Node* root){
  if(root==NULL){
    return make_pair(0,0);
  }
     
    pair<int,int> leftInfo=diam2(root->left); //diam,LH
    pair<int,int> rightInfo=diam2(root->right);//diam,Rh

    int currDiam=leftInfo.second+rightInfo.second+1;
    int finalDiam=max(currDiam,max(leftInfo.first,rightInfo.first));
    int finalHT=max(leftInfo.second,rightInfo.second)+1;

    return make_pair(finalDiam,finalHT);
}

int main() {
    vector<int> Nodes = {1, 2, 4, 9, 10, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1};
    int idx = 0;
    Node* root = buildTree(Nodes, idx);
    cout << "Diameter of the tree: " << diam2(root).first << endl;
    return 0;
}
