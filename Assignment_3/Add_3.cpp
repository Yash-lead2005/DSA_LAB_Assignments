#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }

    bool isFull() { return top == MAX - 1; }

    void push(int x) {
        if (!isFull()) {
            arr[++top] = x;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return -1; // error case
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result[n]; // to store Next Greater Elements
    Stack st;

    // Traverse array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop smaller or equal elements
        while (!st.isEmpty() && st.peek() <= arr[i]) {
            st.pop();
        }

        // If stack becomes empty, no greater element
        if (st.isEmpty()) {
            result[i] = -1;
        } else {
            result[i] = st.peek();
        }

        // Push current element to stack
        st.push(arr[i]);
    }

    cout << "Next Greater Elements are: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
