#include <iostream>
using namespace std;
int findMissing(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1; 
        }
    }
    return n; 
}

int main() {
    int arr[] = {1, 2, 3 ,4, 5, 6};
    int n = 7;
    cout << "Missing number  " << findMissing(arr, n) << endl;
    return 0;
}

