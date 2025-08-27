#include <iostream>
using namespace std;

#define MAX 100   // maximum size of stack

// Stack implementation using array
class Stack {
    char arr[MAX];
    int top;
    
public:
    Stack() {
        top = -1;
    }
    
    // push character into stack
    void push(char c) {
        if (top < MAX - 1) {
            top++;
            arr[top] = c;
        }
    }
    
    // pop character from stack
    char pop() {
        if (top >= 0) {
            char c = arr[top];
            top--;
            return c;
        }
        return '\0'; // return null if empty
    }
    
    // check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;   // reads string without spaces

    Stack st;
    
    // Push all characters of str to stack
    int i = 0;
    while (str[i] != '\0') {
        st.push(str[i]);
        i++;
    }
    
    // Pop characters and print reversed string
    cout << "Reversed string: ";
    while (!st.isEmpty()) {
        cout << st.pop();
    }
    
    cout << endl;
    return 0;
}
