#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char ch) {
        data = ch;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(char ch) {
        Node* newNode = new Node(ch);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isPalindrome() {
        if (!head) return true;  

        Node* left = head;
        Node* right = tail;

        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }

        return true;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    string str;
    cout << "Enter characters ";
    cin >> str;

    for (char ch : str)
        dll.insertAtEnd(ch);

    cout << "Doubly Linked List: ";
    dll.display();

    if (dll.isPalindrome())
        cout << " The ll is a palindrome." << endl;
    else
        cout << " The ll is not a palindrome." << endl;

    return 0;
}
