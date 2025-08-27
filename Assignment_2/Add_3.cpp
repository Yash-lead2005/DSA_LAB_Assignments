#include <iostream>
using namespace std;

void bubbleSort(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    int len1 = 0, len2 = 0;
    while (str1[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;

    if (len1 != len2) {
        cout << "Not Anagrams\n";
        return 0;
    }

    bubbleSort(str1, len1);
    bubbleSort(str2, len2);

    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            cout << "Not Anagrams\n";
            return 0;
        }
    }

    cout << "Anagrams\n";
    return 0;
}
