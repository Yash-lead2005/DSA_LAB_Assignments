#include <iostream>
using namespace std;

#define MAX 100

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
        return -1;
    }

    int peek() {
        if (top >= 0) return arr[top];
        return -1;
    }

    bool isEmpty() {
        return (top == -1);
    }
};

void nearestSmallerToLeft(int A[], int n) {
    Stack st;

    for (int i = 0; i < n; i++) {
        // Pop until we find a smaller element
        while (!st.isEmpty() && st.peek() >= A[i]) {
            st.pop();
        }

        // Print result
        if (st.isEmpty())
            cout << "-1 ";
        else
            cout << st.peek() << " ";

        // Push current element
        st.push(A[i]);
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int A[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << "Nearest smaller to left: ";
    nearestSmallerToLeft(A, n);

    return 0;
}
