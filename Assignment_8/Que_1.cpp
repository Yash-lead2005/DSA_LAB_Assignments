#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    int val;
    cin >> val;
    if(val == -1) return NULL;
    Node* root = new Node(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){
    Node* root = buildTree();
    cout << "Preorder: ";
    preorder(root);
    cout << "Inorder: ";
    inorder(root);
    cout << "Postorder: ";
    postorder(root);
}

