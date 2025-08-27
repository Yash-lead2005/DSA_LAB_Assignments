#include <iostream>
#define MAX 4
using namespace std;

int main() {
    int i, j, a[MAX];

    cout << "Enter diagonal elements:\n";
    for(i = 0; i < MAX; i++)
        cin >> a[i];

    cout << "\nThe diagonal matrix is...\n";
    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++) {
            if(i == j)
                cout << a[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
