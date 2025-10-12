
// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
//     Node* prev;

//     Node(int num) {
//         data = num;
//         next = nullptr;
//         prev = nullptr;
//     }
// };

// class DoublyLinkedList {
// public:
//     Node* head;
//     DoublyLinkedList() {
//         head = nullptr;
//     }

//     void insertAtEnd(int num) {
//         Node* newNode = new Node(num);
//         if (!head) {
//             head = newNode;
//         } else {
//             Node* temp = head;
//             while (temp->next)
//                 temp = temp->next;
//             temp->next = newNode;
//             newNode->prev = temp;
//         }
//     }

//     int size() {
//         int count = 0;
//         Node* temp = head;
//         while (temp) {
//             count++;
//             temp = temp->next;
//         }
//         return count;
//     }
// };

// int main() {
//     DoublyLinkedList dll;
//     dll.insertAtEnd(10);
//     dll.insertAtEnd(20);
//     dll.insertAtEnd(30);
//     dll.insertAtEnd(40);

//     cout << "Size of Doubly Linked List: " << dll.size() << endl;

//     return 0;
// }




// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;

//     Node(int num) {
//         data = num;
//         next = nullptr;
//     }
// };

// class CircularLinkedList {
// public:
//     Node* head;
//     CircularLinkedList() {
//         head = nullptr;
//     }

//     void insertAtEnd(int num) {
//         Node* newNode = new Node(num);
//         if (!head) {
//             head = newNode;
//             head->next = head; // circular link
//         } else {
//             Node* temp = head;
//             while (temp->next != head)
//                 temp = temp->next;
//             temp->next = newNode;
//             newNode->next = head;
//         }
//     }

//     int size() {
//         if (!head)
//             return 0;

//         int count = 0;
//         Node* temp = head;
//         do {
//             count++;
//             temp = temp->next;
//         } while (temp != head);

//         return count;
//     }
// };

// int main() {
//     CircularLinkedList cll;
//     cll.insertAtEnd(20);
//     cll.insertAtEnd(100);
//     cll.insertAtEnd(40);
//     cll.insertAtEnd(80);
//     cll.insertAtEnd(60);

//     cout << "Size of Circular Linked List: " << cll.size() << endl;

//     return 0;
// }
