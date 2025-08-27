#include <iostream>
using namespace std;

#define MAX 5   // Maximum size of stack

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;  // Initialize stack as empty
    }

    // Push element to stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
        } else {
            arr[++top] = x;
            cout << x << " pushed into stack." << endl;
        }
    }

    // Pop element from stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Check if stack is full
    bool isFull() {
        return (top == MAX - 1);
    }

    // Peek top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. Peek" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                if (s.isEmpty())
                    cout << "Stack is Empty." << endl;
                else
                    cout << "Stack is not Empty." << endl;
                break;

            case 4:
                if (s.isFull())
                    cout << "Stack is Full." << endl;
                else
                    cout << "Stack is not Full." << endl;
                break;

            case 5:
                s.peek();
                break;

            case 6:
                s.display();
                break;

            case 7:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
