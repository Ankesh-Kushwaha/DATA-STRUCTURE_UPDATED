#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* LCA(TreeNode* root, int n1, int n2) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == n1 || root->val == n2) {
            return root;
        }

        TreeNode* leftLCA = LCA(root->left, n1, n2);
        TreeNode* rightLCA = LCA(root->right, n1, n2);
        if (leftLCA != nullptr && rightLCA != nullptr) {
            return root;
        }

        return leftLCA != nullptr ? leftLCA : rightLCA;
    }

    int mindis(TreeNode* lca, int n) {
        if (lca == nullptr) {
            return -1;
        }

        if (lca->val == n) {
            return 0;
        }

        int leftdis = mindis(lca->left, n);
        if (leftdis != -1) {
            return leftdis + 1;
        }

        int rightdis = mindis(lca->right, n);
        if (rightdis != -1) {
            return rightdis + 1;
        }
        return -1;
    }

    int minDistance(TreeNode* root, int n1, int n2) {
        TreeNode* lca = LCA(root, n1, n2);
        int dis1 = mindis(lca, n1);
        int dis2 = mindis(lca, n2);
        return dis1 + dis2;
    }

    void findLeaf(TreeNode* root, vector<int>& leaf) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            leaf.push_back(root->val);
            return;
        }
        findLeaf(root->left, leaf);
        findLeaf(root->right, leaf);
    }

public:
    TreeNode* buildTree(const vector<int>& values) {
        if (values.empty()) return nullptr;
        TreeNode* root = new TreeNode(values[0]);
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (i < values.size()) {
            TreeNode* current = q.front();
            q.pop();
            if (i < values.size() && values[i] != -1) {
                current->left = new TreeNode(values[i]);
                q.push(current->left);
            }
            i++;
            if (i < values.size() && values[i] != -1) {
                current->right = new TreeNode(values[i]);
                q.push(current->right);
            }
            i++;
        }
        return root;
    }

    int countPairs(TreeNode* root, int distance) {
        vector<int> leaf;
        findLeaf(root, leaf);
        int ans = 0;
        for (int i = 0; i < leaf.size(); i++) {
            for (int j = i + 1; j < leaf.size(); j++) {
                if (minDistance(root, leaf[i], leaf[j]) <= distance) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> values = {80,62,99,36,45,39,76,81,44,23,58,8,14,1,94,100,10,8,30,75,7,33,80,44,2,67,78,64,30,98,100,24,48,42,31,91,37,81,45,30,77,28};
    TreeNode* root = solution.buildTree(values);
    int distance = 8;  // Example distance, adjust as needed
    int result = solution.countPairs(root, distance);
    cout << "Number of pairs: " << result << endl;
    return 0;
}
