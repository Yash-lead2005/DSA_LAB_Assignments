#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* searchNonRecursive(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

Node* findMax(Node* root) {
    while (root && root->right != NULL) root = root->right;
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left != NULL) root = root->left;
    return root;
}

Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right != NULL) return findMin(node->right);
    Node* succ = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } 
        else if (node->data > root->data)
            root = root->right;
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left != NULL) return findMax(node->left);
    Node* pred = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } 
        else if (node->data < root->data)
            root = root->left;
        else break;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) root = insert(root, arr[i]);

    int key = 40;
    Node* s1 = searchRecursive(root, key);
    Node* s2 = searchNonRecursive(root, key);
    if (s1) cout << "Found Recursively: " << s1->data << endl;
    else cout << "Not Found Recursively\n";
    if (s2) cout << "Found Iteratively: " << s2->data << endl;
    else cout << "Not Found Iteratively\n";

    cout << "Maximum Element: " << findMax(root)->data << endl;
    cout << "Minimum Element: " << findMin(root)->data << endl;

    Node* node = searchRecursive(root, 50);
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);
    if (succ) cout << "Inorder Successor of " << node->data << ": " << succ->data << endl;
    else cout << "No Inorder Successor\n";
    if (pred) cout << "Inorder Predecessor of " << node->data << ": " << pred->data << endl;
    else cout << "No Inorder Predecessor\n";
}

