#include <iostream>
#define MAX 4
using namespace std;

int main() {
    int i, j, size = (MAX*(MAX+1))/2, a[50];

    cout << "Enter elements (row major for lower triangle of symmetric matrix):\n";
    for(i = 0; i < size; i++)
        cin >> a[i];

    cout << "\nThe symmetric matrix is...\n";
    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++) {
            if(i >= j) {
                int idx = (i*(i+1))/2 + j; // index in 1D array
                cout << a[idx] << " ";
            } else {
                int idx = (j*(j+1))/2 + i; // use symmetry
                cout << a[idx] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

