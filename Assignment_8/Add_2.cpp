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

Node** generate(int start, int end, int &size)
{
    if(start > end)
    {
        size = 1;
        Node** arr = new Node*[1];
        arr[0] = NULL;
        return arr;
    }

    int total = 0;
    int range = end - start + 1;
    Node*** temp = new Node**[range];
    int* tempSize = new int[range];

    for(int i = start; i <= end; i++)
    {
        int leftSize = 0;
        int rightSize = 0;

        Node** leftTrees = generate(start, i - 1, leftSize);
        Node** rightTrees = generate(i + 1, end, rightSize);

        int count = leftSize * rightSize;
        tempSize[i - start] = count;
        temp[i - start] = new Node*[count];

        int index = 0;
        for(int l = 0; l < leftSize; l++)
        {
            for(int r = 0; r < rightSize; r++)
            {
                Node* root = new Node(i);
                root->left = leftTrees[l];
                root->right = rightTrees[r];
                temp[i - start][index] = root;
                index++;
            }
        }

        total += count;

        delete[] leftTrees;
        delete[] rightTrees;
    }

    Node** result = new Node*[total];
    int k = 0;

    for(int i = 0; i < range; i++)
    {
        for(int j = 0; j < tempSize[i]; j++)
        {
            result[k] = temp[i][j];
            k++;
        }
        delete[] temp[i];
    }

    delete[] temp;
    delete[] tempSize;

    size = total;
    return result;
}

void preorder(Node* root)
{
    if(root == NULL)
    {
        cout << "null ";
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    cin >> n;

    int size = 0;
    Node** trees = generate(1, n, size);

    for(int i = 0; i < size; i++)
    {
        preorder(trees[i]);
        cout << endl;
    }

    delete[] trees;
    return 0;
}
