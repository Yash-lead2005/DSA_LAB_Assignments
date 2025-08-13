#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str; 
    for (int i = 0; i < str.length() - 1; i++) {
        for (int j = i + 1; j < str.length(); j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    cout << "Sorted string: " << str << endl;
    return 0;
}

