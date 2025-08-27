#include <iostream>
#include <cstring>
#include <cmath> // for pow()
using namespace std;

#define MAX 100

// Stack for integers
class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int x) {
        if (top < MAX - 1) arr[++top] = x;
    }

    int pop() {
        if (top >= 0) return arr[top--];
        return -1; // error case
    }

    bool isEmpty() { return (top == -1); }
};

// function to check operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// function to evaluate postfix
int evaluatePostfix(char postfix[]) {
    Stack st;
    int i = 0;

    while (postfix[i] != '\0') {
        char c = postfix[i];

        // If operand (digit), push into stack
        if (c >= '0' && c <= '9') {
            st.push(c - '0');  // convert char to int
        }
        // If operator, pop two elements and apply
        else if (isOperator(c)) {
            int val2 = st.pop();
            int val1 = st.pop();

            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }

        i++;
    }

    return st.pop();  // final result
}

int main() {
    char postfix[MAX];
    cout << "Enter postfix expression (use digits only): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Evaluated result: " << result << endl;

    return 0;
}
