#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

void splitList(Node *head, Node* &head1, Node* &head2) {
    Node *slow = head;
    Node *fast = head;

    if (head == nullptr)
        return;

    while (fast->next != head && fast->next->next != head) { // fast next for odd case and fast next next for even case
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast->next->next == head)
        fast = fast->next;

    head1 = head;
    head2 = slow->next;

    fast->next = slow->next;

    slow->next = head;
}

void printList(Node *head) {
    Node *curr = head;
    if (head != nullptr) {
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
}

int main() {
    Node *head = new Node(1);
    Node *head1 = nullptr;
    Node *head2 = nullptr;

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
   // head->next->next->next->next = head;

   head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head;
    splitList(head, head1, head2);

    printList(head1);
    printList(head2);

    return 0;
}
