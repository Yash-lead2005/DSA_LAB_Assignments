#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

void removeLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) return;

    Node* slow = head;
    Node* fast = head;

    bool loopExists = false;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopExists = true;
            break;
        }
    }

    if (!loopExists) return; 

    slow = head;
    Node* prev = nullptr; 
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = nullptr;
}

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

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 5; i++) {
        insertAtTail(head, i);
    }

 
    head->next->next->next->next->next = head->next->next; 

    removeLoop(head);

    cout << "Linked List after removing loop: ";
    printList(head);

    return 0;
}
