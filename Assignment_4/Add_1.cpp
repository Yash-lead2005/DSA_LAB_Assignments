#include <iostream>
using namespace std;

void genBin(int n) {
    for (int i = 1; i <= n; i++) {
        int num = i;
        int bin[32]; 
        int j = 0;

        while (num > 0) {
            bin[j++] = num % 2;
            num = num / 2;
        }

        for (int k = j - 1; k >= 0; k--) {
            cout << bin[k];
        }
        cout << endl;
    }
}

int main() {
    genBin(5);
    return 0;
}
