#include <iostream>
using namespace std;

int countInversions(int A[], int n) {
    int invCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                invCount++;
            }
        }
    }
    return invCount;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int A[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << "Number of inversions = " << countInversions(A, n) << endl;
    return 0;
}
