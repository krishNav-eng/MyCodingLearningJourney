#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
        
    }
    void inorder(TreeNode* root, vector<int> &result) {
        if(!root) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    void preorder(TreeNode* root, vector<int> &result) {
        if(!root) return;
        result.push_back(root->val);
        preorder(root->left, result);
        
        preorder(root->right, result);
    }

    void postorder(TreeNode* root, vector<int> &result) {
        if(!root) return;
        postorder(root->left, result);
        
        postorder(root->right, result);
        result.push_back(root->val);
    }
};