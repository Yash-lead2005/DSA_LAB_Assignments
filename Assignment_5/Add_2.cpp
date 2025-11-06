#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* reverseKthplace(Node* head , int k){
Node* current = head;
Node* next = nullptr;
Node* prev = nullptr;
int count =0;

Node* temp = head;
int nodescount =0;
while(temp != nullptr && nodescount <k){
    temp = temp->next;
    nodescount++;
}

if(nodescount<k) return head;

while(current != nullptr && count < k){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
}

if(next != nullptr ){
    head->next = reverseKthplace(next,k);
}
return prev ;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    Node* head = nullptr;


    int values[] = {1, 2, 3, 4, 5, 6, 7, 8};
    for (int val : values) {
        insertAtTail(head, val);
    }

    int k = 3;
    cout << "Original List: ";
    printList(head);

    head = reverseKthplace(head, k);

    cout << "Modified List: ";
    printList(head);

    return 0;
}


