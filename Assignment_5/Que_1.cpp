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

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at the beginning.\n";
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            cout << "Inserted " << val << " at the end.\n";
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        cout << "Inserted " << val << " at the end.\n";
    }

    void insertBeforeAfter(int val, int key, bool after) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        if (after) {
            Node* temp = head;
            while (temp && temp->data != key)
                temp = temp->next;

            if (!temp) {
                cout << "Node " << key << " not found.\n";
                return;
            }

            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << val << " after " << key << ".\n";
        } else {
            if (head->data == key) {
                insertAtBeginning(val);
                return;
            }

            Node* prev = nullptr;
            Node* curr = head;

            while (curr && curr->data != key) {
                prev = curr;
                curr = curr->next;
            }

            if (!curr) {
                cout << "Node " << key << " not found.\n";
                return;
            }

            Node* newNode = new Node(val);
            newNode->next = curr;
            prev->next = newNode;
            cout << "Inserted " << val << " before " << key << ".\n";
        }
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        if (!head->next) {
            cout << "Deleted " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;

        cout << "Deleted " << temp->next->data << " from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpecificNode(int key) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted node " << key << ".\n";
            delete temp;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        while (curr && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if (!curr) {
            cout << "Node " << key << " not found.\n";
            return;
        }

        prev->next = curr->next;
        cout << "Deleted node " << key << ".\n";
        delete curr;
    }

    void searchNode(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << key << " not found.\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, key;
    bool after;

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After a Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete a Specific Node\n";
        cout << "7. Search a Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter key node value: ";
            cin >> key;
            cout << "Insert after(1) or before(0)? ";
            cin >> after;
            list.insertBeforeAfter(val, key, after);
            break;
        case 4:
            list.deleteFromBeginning();
            break;
        case 5:
            list.deleteFromEnd();
            break;
        case 6:
            cout << "Enter node value to delete: ";
            cin >> key;
            list.deleteSpecificNode(key);
            break;
        case 7:
            cout << "Enter node value to search: ";
            cin >> key;
            list.searchNode(key);
            break;
        case 8:
            list.display();
            break;
        case 9:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
