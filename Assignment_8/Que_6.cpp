#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[100];
    int size;
public:
    PriorityQueue() {
        size = 0;
    }

    void insert(int val) {
        if (size >= 100) {
            cout << "Priority Queue is full" << endl;
            return;
        }
        arr[size] = val;
        int i = size;
        size++;

        while (i > 0) {
            int parent = (i - 1) / 2;
            if (arr[parent] < arr[i]) {
                int temp = arr[parent];
                arr[parent] = arr[i];
                arr[i] = temp;
                i = parent;
            } else {
                break;
            }
        }
    }

    void remove() {
        if (size <= 0) {
            cout << "Priority Queue is empty" << endl;
            return;
        }
        arr[0] = arr[size - 1];
        size--;

        int i = 0;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && arr[left] > arr[largest]) {
                largest = left;
            }
            if (right < size && arr[right] > arr[largest]) {
                largest = right;
            }
            if (largest != i) {
                int temp = arr[i];
                arr[i] = arr[largest];
                arr[largest] = temp;
                i = largest;
            } else {
                break;
            }
        }
    }

    int top() {
        if (size <= 0) {
            cout << "Priority Queue is empty" << endl;
            return -1;
        }
        return arr[0];
    }

    bool empty() {
        return size == 0;
    }

    void display() {
        if (size <= 0) {
            cout << "Priority Queue is empty" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(40);
    pq.insert(10);
    pq.insert(30);
    pq.insert(50);
    pq.insert(20);

    cout << "Priority Queue elements: ";
    pq.display();

    cout << "Top element: " << pq.top() << endl;

    pq.remove();
    cout << "After removing top element: ";
    pq.display();

    cout << "Top element now: " << pq.top() << endl;

    return 0;
}
