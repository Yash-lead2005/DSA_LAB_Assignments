#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return NULL;
    Node* root = new Node(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

bool isBSTUtil(Node* root, long minVal, long maxVal) {
    if (root == NULL) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {
    cout << "Enter tree elements in preorder (-1 for NULL): ";
    Node* root = buildTree();
    if (isBST(root)) cout << "The given binary tree is a BST";
    else cout << "The given binary tree is NOT a BST";
}

