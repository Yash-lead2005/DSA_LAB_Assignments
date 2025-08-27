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
    cout << "Enter number of days: ";
    cin >> n;

    int temp[n];
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) cin >> temp[i];

    int ans[n];
    for (int i = 0; i < n; i++) ans[i] = 0; // default 0

    Stack st; // store indexes, not values

    for (int i = 0; i < n; i++) {
        // while current temperature is greater than top of stack’s temperature
        while (!st.isEmpty() && temp[i] > temp[st.peek()]) {
            int idx = st.pop();
            ans[idx] = i - idx;  // days waited
        }
        st.push(i); // push current index
    }

    cout << "Answer array: ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
