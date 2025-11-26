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

// Insert in BST (simple)
Node* insertBST(Node* root, int x) {
    if (root == NULL)
        return new Node(x);

    if (x < root->val)
        root->left = insertBST(root->left, x);
    else
        root->right = insertBST(root->right, x);

    return root;
}

// Convert BST to sorted DLL using inorder traversal
void bstToDLL(Node* root, Node*& head, Node*& prev) {
    if (root == NULL)
        return;

    bstToDLL(root->left, head, prev);

    if (prev == NULL) {
        head = root;          // first node becomes head
    } else {
        prev->right = root;   // doubly linking
        root->left = prev;
    }
    prev = root;

    bstToDLL(root->right, head, prev);
}

// Merge two sorted DLLs
Node* mergeDLL(Node* h1, Node* h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    Node* head = NULL;
    Node* tail = NULL;

    if (h1->val < h2->val) {
        head = h1;
        h1 = h1->right;
    } else {
        head = h2;
        h2 = h2->right;
    }

    tail = head;

    while (h1 != NULL && h2 != NULL) {
        if (h1->val < h2->val) {
            tail->right = h1;
            h1->left = tail;
            tail = h1;
            h1 = h1->right;
        } else {
            tail->right = h2;
            h2->left = tail;
            tail = h2;
            h2 = h2->right;
        }
    }

    while (h1 != NULL) {
        tail->right = h1;
        h1->left = tail;
        tail = h1;
        h1 = h1->right;
    }

    while (h2 != NULL) {
        tail->right = h2;
        h2->left = tail;
        tail = h2;
        h2 = h2->right;
    }

    return head;
}

// Print DLL
void printDLL(Node* head) {
    while (head != NULL) {
        cout << head->val << " <--> ";
        head = head->right;
    }
    cout << "null" << endl;
}

int main() {

    // Example BST 1
    Node* T1 = NULL;
    T1 = insertBST(T1, 20);
    insertBST(T1, 10);
    insertBST(T1, 30);
    insertBST(T1, 25);
    insertBST(T1, 100);

    // Example BST 2
    Node* T2 = NULL;
    T2 = insertBST(T2, 50);
    insertBST(T2, 5);
    insertBST(T2, 70);

    // Convert T1 to DLL
    Node *head1 = NULL, *prev1 = NULL;
    bstToDLL(T1, head1, prev1);

    // Convert T2 to DLL
    Node *head2 = NULL, *prev2 = NULL;
    bstToDLL(T2, head2, prev2);

    // Merge DLLs
    Node* finalDLL = mergeDLL(head1, head2);

    // Print final doubly linked list
    printDLL(finalDLL);

    return 0;
}
