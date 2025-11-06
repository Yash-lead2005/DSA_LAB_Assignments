#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int value) {
        data = value;
        prev = next = nullptr;
    }
};

void display(Node* head) {
    if (head == nullptr) return;

    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

void splitll(Node* head) {
    if (head == nullptr) return;

    Node* slow = head;
    Node* fast = head;
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    if (fast->next->next == head)
        fast = fast->next;


    head1 = head;
    head2 = slow->next;

    fast->next = head2;
    slow->next = head1;

    cout << "First half: ";
    display(head1);

    cout << "Second half: ";
    display(head2);
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head; 

    splitll(head);

    return 0;
}
