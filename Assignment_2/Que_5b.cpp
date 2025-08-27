#include <iostream>
#define MAX 4
using namespace std;

int main() {
    int i, j, k = 0, size = 3*MAX - 2, a[50];

    cout << "Enter elements (row major for tri-diagonal):\n";
    for(i = 0; i < size; i++)
        cin >> a[i];

    cout << "\nThe tri-diagonal matrix is...\n";
    k = 0;
    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++) {
            if(j == i-1)        // lower diagonal
                cout << a[k++] << " ";
            else if(j == i)     // main diagonal
                cout << a[k++] << " ";
            else if(j == i+1)   // upper diagonal
                cout << a[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
