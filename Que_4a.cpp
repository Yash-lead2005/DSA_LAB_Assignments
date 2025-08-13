#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter first string: "<<endl;
    getline(cin, str1);
    cout << "Enter second string: "<<endl;
    getline(cin, str2);
    string result1 = str1 + str2;
    cout << "Concatenated string (using +): " << result1 <<endl;
    return 0;
}



