#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
}

// this code will work for a general binary tree
int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}


// Optimized approach for COMPLETE binary tree
// A complete binary tree is:
// 1. Every level, except possibly the last, is completely filled.
// 2. All nodes are as far left as possible.
// this code won't work for a general binary tree
int countNodes(TreeNode* root) {
    if (!root) return 0;

    int leftDepth = 0;
    TreeNode* leftNode = root;
    while (leftNode) {
        leftDepth++;
        leftNode = leftNode->left;
    }

    int rightDepth = 0;
    TreeNode* rightNode = root;
    while (rightNode) {
        rightDepth++;
        rightNode = rightNode->right;
    }

    if (leftDepth == rightDepth) {
        return (1 << leftDepth) - 1; // 2^depth - 1
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}


int main() {

}