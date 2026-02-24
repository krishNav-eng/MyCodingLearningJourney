#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string val) : data(val), left(nullptr), right(nullptr) {}
};


void perimeter(Node* root, vector<string>& result) {
    if(!root->left && !root->right) {
        result.push_back(root->data);
        return;
    }
    result.push_back(root->data);
    if(root->right) perimeter(root->right, result);
    if(root->left) perimeter(root->left, result);
}


int main() {
    Node* root = new Node("A");
    root->left = new Node("B");
    root->right = new Node("C");
    root->left->left = new Node("D");
    root->left->right = new Node("E");
    root->right->right = new Node("F");

    vector<string> result;
    perimeter(root, result);

    for(const string& val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}