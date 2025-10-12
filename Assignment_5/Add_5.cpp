#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int coeff;
        int pow;
        Node* next;
        Node(int c, int p) {
            coeff = c;
            pow = p;
            next = nullptr;
        }
};

Node* addPolynomial(Node* head1, Node* head2) {

    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    if (head1->pow > head2->pow) {
      Node* nextPtr = addPolynomial(head1->next, head2);
      head1->next = nextPtr;
      return head1;
    }

    else if (head1->pow < head2->pow) {
      Node* nextPtr = addPolynomial(head1, head2->next);
      head2->next = nextPtr;
      return head2;
    }

    Node* nextPtr = addPolynomial(head1->next, head2->next);
    head1->coeff += head2->coeff;
    head1->next = nextPtr;
    return head1;
}

void printList(Node* head) {
    Node* curr = head;

    while (curr != nullptr) {
        cout << curr->coeff << "," << curr->pow <<" ";
        curr = curr->next;
    }
    
    cout<<endl;
}

int main() {
    
    Node* head1 = new Node(5,2); 
    head1->next = new Node(4,1);
    head1->next->next = new Node(2,0);
    
    Node* head2 = new Node(-5,1); 
    head2->next = new Node(-5,0);

    Node* head = addPolynomial(head1, head2);

    printList(head);
}
