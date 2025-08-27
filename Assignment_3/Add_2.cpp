#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<int> s; 
    stack<int> minStack; 

public:
    void push(int x) {
        s.push(x);

        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        } else {
            
   
            minStack.push(minStack.top());
        }
    }

    
    int pop() {
        if (s.empty()) {
            return -1;
        }
  
        int poppedElement = s.top();
        s.pop();
        minStack.pop();
        return poppedElement;
    }

  
    int peek() {
        if (s.empty()) {
            return -1;
        }
        return s.top();
    }

    bool isEmpty() {
        return s.empty();
    }


    int getMin() {
        if (minStack.empty()) {
            return -1;
        }
        return minStack.top();
    }
};

int main() {
    SpecialStack stack;
    
    stack.push(18);
    stack.push(19);
    stack.push(29);
    stack.push(15);
    stack.push(16);

    cout << stack.getMin() << endl;

    return 0;
}
