#include <iostream>
using namespace std;

int countOnes(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

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

class DoublyLinkedList {
public:
    DNode* head;
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void removeEvenParity() {
        DNode* curr = head;
        while (curr) {
            int ones = countOnes(curr->data);
            if (ones % 2 == 0) {
                DNode* toDelete = curr;
                if (curr->prev)
                    curr->prev->next = curr->next;
                else
                    head = curr->next; 

                if (curr->next)
                    curr->next->prev = curr->prev;

                curr = curr->next;
                delete toDelete;
            } else {
                curr = curr->next;
            }
        }
    }


    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// CIRCULAR  LINKED LIST 
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() {
        head = nullptr;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void removeEvenParity() {
        if (!head) return;

        while (head && countOnes(head->data) % 2 == 0) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }

            Node* temp = head;
            Node* last = head;
            while (last->next != head)
                last = last->next;

            head = head->next;
            last->next = head;
            delete temp;
        }

        if (!head) return;

        Node* curr = head->next;
        Node* prev = head;

        while (curr != head) {
            if (countOnes(curr->data) % 2 == 0) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    void display() {
        if (!head) {
            cout << "List empty" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};


int main() {
    DoublyLinkedList dll;
    dll.insertEnd(11);
    dll.insertEnd(15);
    dll.insertEnd(7);
    dll.insertEnd(10);
    dll.insertEnd(9);

    cout << "Doubly Linked List: ";
    dll.display();

    dll.removeEvenParity();
    cout << "After removing even parity (DLL): ";
    dll.display();

    CircularLinkedList cll;
    cll.insertEnd(5);
    cll.insertEnd(8);
    cll.insertEnd(11);
    cll.insertEnd(15);
    cll.insertEnd(6);

    cout << "\n Circular Linked List: ";
    cll.display();

    cll.removeEvenParity();
    cout << " removing even parity (CSLL): ";
    cll.display();

    return 0;
}


