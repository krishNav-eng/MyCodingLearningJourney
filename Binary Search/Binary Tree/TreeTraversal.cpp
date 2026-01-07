#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int main() {
    
}

void preoder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    result.push_back(root->val);
    preoder(root->left, result);
    preoder(root->right, result);
}


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;

    if (root == nullptr) return result;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);

        if (node->right) {
            st.push(node->right);
        }
        if (node->left) {
            st.push(node->left);
        }
    }
}


vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    if(root==nullptr) return result;

    stack<TreeNode*> st;
    st.push(root)
}