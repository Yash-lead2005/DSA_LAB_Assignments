#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

int searchIndex(int inorder[], int start, int end, int key) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == key)
            return i;
    }
    return -1;
}


Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int& postIndex) {
    if (inStart > inEnd)
        return NULL;
    Node* root = new Node(postorder[postIndex]);
    postIndex--;

    if (inStart == inEnd)
        return root;

    int inIndex = searchIndex(inorder, inStart, inEnd, root->val);

    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

void printPreorder(Node* root) {
    if (root == NULL)
        return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {

    int n;
    cin >> n;

    int* inorder = new int[n];
    int* postorder = new int[n];

    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];

    int postIndex = n - 1; 
    Node* root = buildTree(inorder, postorder, 0, n - 1, postIndex);


    printPreorder(root);
    cout << endl;

    return 0;
}
