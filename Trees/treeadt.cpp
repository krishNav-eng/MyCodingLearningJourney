#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node* parentNode; // Reference to parent for depth calculation
    std::vector<Node*> children;

    Node(std::string val, Node* p = nullptr) : data(val), parentNode(p) {}

    // Logic from the slide
    bool isRoot() const { 
        return parentNode == nullptr; 
    }

    // Recursive depth calculation
    int depth() const {
        if (this->isRoot()) {
            return 0;
        }
        return 1 + this->parentNode->depth();
    }
};