#include <iostream>
using namespace std;

#define MAX 100

// Stack implementation
class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char c) {
        if (top < MAX - 1) {
            arr[++top] = c;
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return '\0'; // empty
    }

    char peek() {
        if (top >= 0) return arr[top];
        return '\0';
    }

    bool isEmpty() {
        return (top == -1);
    }
};

// function to check matching brackets
bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

// main function to check balance
bool isBalanced(char exp[]) {
    Stack st;
    int i = 0;
    while (exp[i] != '\0') {
        char c = exp[i];

        // if opening bracket, push
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        // if closing bracket, check match
        else if (c == ')' || c == '}' || c == ']') {
            if (st.isEmpty() || !isMatchingPair(st.pop(), c)) {
                return false; // not balanced
            }
        }
        i++;
    }
    return st.isEmpty(); // balanced if stack is empty
}

int main() {
    char exp[100];
    cout << "Enter expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Balanced Expression\n";
    else
        cout << "Not Balanced Expression\n";

    return 0;
}
