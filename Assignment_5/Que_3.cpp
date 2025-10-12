#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

class Linkedlist{
 public:
    Node*head;

    Linkedlist(){
        head = nullptr;
    }

    void insert(int value){
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }


    void findMiddle(){
        if(head == nullptr){
            cout<<"list is empty"<<endl;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        cout<<"Middle is "<<slow->data<<endl;
    }

     void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    Linkedlist list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Linked List: ";
    list.display();

    list.findMiddle();

    return 0;
}


