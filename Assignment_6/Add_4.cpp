#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) {
        data = val;
        next = prev = nullptr;
    }
};

void correctPrevPointers(DNode* head) {
    if (!head) return;

    DNode* curr = head;
    while (curr && curr->next) {
        if (curr->next->prev != curr) {
            curr->next->prev = curr;
        }
        curr = curr->next;
    }
}

void printList(DNode* head) {
    DNode* temp = head;
    cout << "Forward: ";
    while (temp) {
        cout << temp->data << " ";
        if (!temp->next) break;
        temp = temp->next;
    }
    cout << "\nBackward: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    DNode* head = new DNode(1);
    head->next = new DNode(2);
    head->next->next = new DNode(3);

    head->next->prev = nullptr; 

    cout << "Before correction:" << endl;
    printList(head);

    correctPrevPointers(head);

    cout << "\nAfter correction:" << endl;
    printList(head);

    return 0;
}
