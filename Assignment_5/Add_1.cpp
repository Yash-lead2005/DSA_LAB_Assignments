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

Node* getIntersectionNode( Node* A , Node* B){
    Node* firstcurrnode = A;
    while(firstcurrnode != NULL){
        Node* secondcurrnode = B;
        while(secondcurrnode != NULL){
            if(firstcurrnode == secondcurrnode){
                return firstcurrnode;
            }
            secondcurrnode = secondcurrnode->next;
        }
        firstcurrnode = firstcurrnode->next;
    }
    return NULL;
}


int main() {
   
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = new Node(8);
    headA->next->next->next = new Node(5);

 
    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);

   
    headB->next->next->next = headA->next->next; 

    Node* intersection = getIntersectionNode(headA, headB);

    if(intersection) {
        cout << "Intersected at " << intersection->data << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}

