#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node*prev;

    Node(int num){
        data = num;
        next = nullptr;
        prev = nullptr;
    }
};
class DoublyLinkedList {
    public:
    Node*head;
    DoublyLinkedList(){
        head = nullptr;
    }

    bool search(int value){
        Node* current = head;
        while(current){
            if(current->data == value){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void insertAtBegin(int num){
        Node*newNode = new Node(num);
        if(!head){
            head = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int num) {
        Node* newNode= new Node(num);
        if (!head) {
            head = newNode;
        } 
        else {
            Node* current = head;
            while (current->next) {
            current = current->next;
            }
            current->next = newNode;
            newNode->prev= current;
        }
    }

    void insertAfterValue(int value, int num) {
        Node* newNode= new Node(num);
        Node* current = head;
        while (current) {
            if (current->data == value) {
                newNode->next = current->next;
                newNode->prev= current;
             if (current->next) {
                current->next->prev= newNode;
            }
                current->next = newNode;
                return;
            }
            current = current->next;
        }   
        cout<< "Value " << value << " not found in the list." <<endl;
    }


    void deleteAtBegin() {
        if (!head) {
             cout<< "List is Empty. Nothing to delete." <<endl;
             return;
        }
        Node* temp = head;
        head = head->next;

        if (head) {
            head->prev= nullptr;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) {
            cout<< "List is Empty. Nothing to delete." <<endl;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        if (current->prev) {
            current->prev->next = nullptr;
        } 
        else {
            head = nullptr;
        }
        delete current;
    }


    void deleteSpecificValue(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                Node* temp = current->next;
            if (temp) {
                current->next = temp->next;
            if (temp->next) {
                temp->next->prev= current;
            }
            delete temp;
            } 
            else {
                cout<< "No element to delete after " << value << "." << endl;
            }
            return;
            }
            current = current->next;
        }
        cout<< "Value " << value << " not found in the list." << endl;
    }

      void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* current = head;
        cout << "Doubly Linked List: ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};



int main(){
    DoublyLinkedList dll;
    int choice, value, num;

    do {
        cout << "\n====== DOUBLY LINKED LIST MENU ======\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Specific Value\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search for Value\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> num;
                dll.insertAtBegin(num);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> num;
                dll.insertAtEnd(num);
                break;
            case 3:
                cout << "Enter value after which to insert: ";
                cin >> value;
                cout << "Enter value to insert: ";
                cin >> num;
                dll.insertAfterValue(value, num);
                break;
            case 4:
                dll.deleteAtBegin();
                break;
            case 5:
                dll.deleteAtEnd();
                break;
            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                dll.deleteSpecificValue(value);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                if (dll.search(value))
                    cout << value << " found in the list.\n";
                else
                    cout << value << " not found.\n";
                break;
            case 8:
                dll.display();
                break;
            case 9:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);
    return 0;
}