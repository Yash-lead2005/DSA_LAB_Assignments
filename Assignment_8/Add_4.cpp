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

int main() {

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }


        Node** nodes = new Node*[n];
        for (int i = 0; i < n; i++) {
            if (arr[i] == -1)
                nodes[i] = NULL;
            else
                nodes[i] = new Node(arr[i]);
        }

        for (int i = 0; i < n; i++) {
            if (nodes[i] != NULL) {
                int leftIndex = 2 * i + 1;
                int rightIndex = 2 * i + 2;

                if (leftIndex < n)
                    nodes[i]->left = nodes[leftIndex];

                if (rightIndex < n)
                    nodes[i]->right = nodes[rightIndex];
            }
        }

        Node* root = nodes[0];

        if (root == NULL) {
            cout << endl;
            continue;
        }

        Node** q = new Node*[n];
        int front = 0, rear = 0;

        q[rear++] = root;
        int nodesThisLevel = 1;

        int first = 1;

        while (front < rear) {

            int nodesNextLevel = 0;
            Node* lastNode = NULL;

            for (int i = 0; i < nodesThisLevel; i++) {

                Node* curr = q[front++];
                lastNode = curr;

                if (curr->left != NULL) {
                    q[rear++] = curr->left;
                    nodesNextLevel++;
                }
                if (curr->right != NULL) {
                    q[rear++] = curr->right;
                    nodesNextLevel++;
                }
            }

            if (first == 1) {
                cout << lastNode->val;
                first = 0;
            } else {
                cout << " " << lastNode->val;
            }

            nodesThisLevel = nodesNextLevel;
        }

        cout << endl;
        for (int i = 0; i < n; i++)
            if (nodes[i] != NULL) delete nodes[i];

        delete[] nodes;
        delete[] arr;
        delete[] q;
    }

    return 0;
}
