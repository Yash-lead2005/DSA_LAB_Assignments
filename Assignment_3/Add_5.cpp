#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    int peek() { return arr[top]; }
};

int main() {
    int n;
    cout << "Enter size of array A: ";
    cin >> n;

    int A[n];
    cout << "Enter elements of array A: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    Stack S;
    int B[n], idxB = 0;

    int expected = 1;  // expecting sorted order 1..N
    int i = 0;

    while (i < n || !S.isEmpty()) {
        if (i < n && A[i] == expected) {
            // Directly move A[i] to B
            B[idxB++] = A[i];
            i++;
            expected++;
        } 
        else if (!S.isEmpty() && S.peek() == expected) {
            // Pop from stack to B
            B[idxB++] = S.pop();
            expected++;
        } 
        else if (i < n) {
            // Push A[i] to stack
            S.push(A[i]);
            i++;
        } 
        else {
            break; // stuck
        }
    }

    bool possible = true;
    for (int j = 1; j < n; j++) {
        if (B[j] < B[j - 1]) {
            possible = false;
            break;
        }
    }

    if (possible) cout << "Yes, possible to sort into B" << endl;
    else cout << "No, not possible" << endl;

    return 0;
}
