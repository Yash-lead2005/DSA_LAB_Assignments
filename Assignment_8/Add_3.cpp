#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Queue
{
public:
    Node** arr;
    int front;
    int rear;
    int size;

    Queue(int n)
    {
        arr = new Node*[n];
        front = 0;
        rear = 0;
        size = n;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    void push(Node* node)
    {
        arr[rear] = node;
        rear++;
    }

    Node* pop()
    {
        Node* temp = arr[front];
        front++;
        return temp;
    }

    ~Queue()
    {
        delete[] arr;
    }
};

Node* buildTree(int nodes[], int n)
{
    if(n == 0 || nodes[0] == -1)
    {
        return NULL;
    }

    Node* root = new Node(nodes[0]);
    Queue q(n);
    q.push(root);
    int i = 1;

    while(i < n && !q.isEmpty())
    {
        Node* current = q.pop();

        if(i < n && nodes[i] != -1)
        {
            current->left = new Node(nodes[i]);
            q.push(current->left);
        }
        i++;

        if(i < n && nodes[i] != -1)
        {
            current->right = new Node(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int maxDepth(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    if(leftDepth > rightDepth)
    {
        return leftDepth + 1;
    }
    else
    {
        return rightDepth + 1;
    }
}

int main()
{
    int T;
    cin >> T;

    for(int t = 0; t < T; t++)
    {
        int n;
        cin >> n;

        int* nodes = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin >> nodes[i];
        }

        Node* root = buildTree(nodes, n);
        cout << maxDepth(root) << endl;

        delete[] nodes;
    }

    return 0;
}
