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

class CountOccur{
public:
    Node* head;
    CountOccur(){
        head = nullptr;
    }

    void insert(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void Delete(int key){
        if(head == nullptr ) return ;

        Node* temp = head;
        Node*pre = nullptr;

        if (head->data == key) {
            head = head->next;
            delete temp;
            return;
        }

        while(temp != nullptr && temp->data != key){
            pre = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;
        pre->next = temp->next;
        delete temp;
    }

    void searchKey(int key){
        int count =0;
        Node* current = head;
        while(current != nullptr){
            if(current->data == key){
                count++;
            }
            current = current->next;
        }
        cout<<"count is = "<<count<<endl;

         while (true) {
            Node* current = head;
    
            while (current != nullptr && current->data != key)
                current = current->next;

            if (current == nullptr) break; // no more occurrences
            Delete(key);
        }

    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main(){
    CountOccur list;
    list.insert(1);
    list.insert(4);
    list.insert(1);
    list.insert(3);
    list.insert(5);
    list.insert(1);
    list.insert(1);
    cout<<"Linked list is : "<<endl;
    list.display();
    list.searchKey(1);
    list.searchKey(2);
    list.display();
    return 0;
}
