#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

bool isCircular(Node* head) {
    if (head == nullptr)
        return false; 

    Node* temp = head->next;

    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}

int main() {
 
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);


    head->next = second;
    second->next = third;
    third->next = fourth;


    if (isCircular(head))
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is not circular." << endl;

    return 0;
}
