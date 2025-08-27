#include <iostream>
using namespace std;

#define MAX 100

class SpecialStack {
    long long arr[MAX];
    int top;
    long long minElement;

public:
    SpecialStack() {
        top = -1;
        minElement = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void push(long long x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        if (isEmpty()) {
            top++;
            arr[top] = x;
            minElement = x;
        } else if (x >= minElement) {
            top++;
            arr[top] = x;
        } else {
            // store encoded value
            long long encoded = 2*x - minElement;
            top++;
            arr[top] = encoded;
            minElement = x;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        long long t = arr[top--];
        if (t < minElement) {
            // encoded value → restore old min
            minElement = 2*minElement - t;
        }
    }

    long long peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        long long t = arr[top];
        if (t >= minElement)
            return t;
        else
            return minElement; // real top
    }

    long long getMin() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minElement;
    }
};

int main() {
    SpecialStack st;

    st.push(3);
    st.push(5);
    cout << "Min: " << st.getMin() << endl; // 3

    st.push(2);
    st.push(1);
    cout << "Min: " << st.getMin() << endl; // 1

    st.pop();
    cout << "Min: " << st.getMin() << endl; // 2

    st.pop();
    cout << "Top: " << st.peek() << endl;   // 5
    cout << "Min: " << st.getMin() << endl; // 3

    return 0;
}
