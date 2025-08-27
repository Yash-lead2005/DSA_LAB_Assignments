#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

// Stack for operators
class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(char c) {
        if (top < MAX - 1) arr[++top] = c;
    }

    char pop() {
        if (top >= 0) return arr[top--];
        return '\0';
    }

    char peek() {
        if (top >= 0) return arr[top];
        return '\0';
    }

    bool isEmpty() { return (top == -1); }
};

// function to return precedence
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// check if operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// infix to postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    Stack st;
    int i = 0, k = 0;

    while (infix[i] != '\0') {
        char c = infix[i];

        // Operand → directly to postfix
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[k++] = c;
        }
        // Left parenthesis → push
        else if (c == '(') {
            st.push(c);
        }
        // Right parenthesis → pop until '('
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix[k++] = st.pop();
            }
            st.pop(); // remove '('
        }
        // Operator
        else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
                postfix[k++] = st.pop();
            }
            st.push(c);
        }

        i++;
    }

    // pop remaining operators
    while (!st.isEmpty()) {
        postfix[k++] = st.pop();
    }

    postfix[k] = '\0'; // null terminate
}

int main() {
    char infix[MAX], postfix[MAX];
    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
