 #include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int num) {
        data = num;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int num) {
        Node* newNode = new Node(num);
        if (!head) {
            head = newNode;
            head->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }


    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);


        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);

    cll.display();

    return 0;
}