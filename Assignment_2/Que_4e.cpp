#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    for (int i = 0; str[i] != '\0'; i++) {
        int ch = str[i]; 
        if (ch >= 65 && ch <= 90) { 
            ch = ch + 32; 
        }
        str[i] = (char)ch; 
    }

    cout << "Lowercase string: " << str << endl;
    return 0;
}

