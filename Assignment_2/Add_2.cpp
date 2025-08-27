#include <iostream>
using namespace std;

// Function to check if arr1 (length len1) is substring of arr2 (length len2)
bool isSubstring(char arr1[], int len1, char arr2[], int len2) {
    if (len1 > len2) return false;

    for (int i = 0; i <= len2 - len1; i++) {
        int k = 0;
        while (k < len1 && arr2[i + k] == arr1[k]) {
            k++;
        }
        if (k == len1) return true; // found match
    }
    return false;
}

int main() {
    char s[100];
    cout << "Enter string: ";
    cin >> s;

    // find length manually
    int n = 0;
    while (s[n] != '\0') n++;

    bool possible = false;

    // split at positions i and j
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // part1 = s[0..i-1]
            // part2 = s[i..j-1]
            // part3 = s[j..n-1]

            int len1 = i;
            int len2 = j - i;
            int len3 = n - j;

            char part1[100], part2[100], part3[100];

            // copy manually
            for (int k = 0; k < len1; k++) part1[k] = s[k];
            part1[len1] = '\0';

            for (int k = 0; k < len2; k++) part2[k] = s[i + k];
            part2[len2] = '\0';

            for (int k = 0; k < len3; k++) part3[k] = s[j + k];
            part3[len3] = '\0';

            // check substring condition
            if ((isSubstring(part1, len1, part2, len2) && isSubstring(part1, len1, part3, len3)) ||
                (isSubstring(part2, len2, part1, len1) && isSubstring(part2, len2, part3, len3)) ||
                (isSubstring(part3, len3, part1, len1) && isSubstring(part3, len3, part2, len2))) {
                
                possible = true;
                cout << "YES\n";
                cout << "Split: ";
                for (int k = 0; k < len1; k++) cout << part1[k];
                cout << " | ";
                for (int k = 0; k < len2; k++) cout << part2[k];
                cout << " | ";
                for (int k = 0; k < len3; k++) cout << part3[k];
                cout << endl;
                return 0;
            }
        }
    }

    if (!possible) cout << "NO\n";
    return 0;
}
