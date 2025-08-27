#include <iostream>
#define MAX 4
using namespace std;

int main() {
    int i, j, k = 0, size = (MAX*(MAX+1))/2, a[50];

    cout << "Enter elements (row major for lower triangular):\n";
    for(i = 0; i < size; i++)
        cin >> a[i];

    cout << "\nThe lower triangular matrix is...\n";
    k = 0;
    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++) {
            if(i >= j)
                cout << a[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
