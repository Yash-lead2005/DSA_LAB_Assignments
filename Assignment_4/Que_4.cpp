#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s;
    cout << "Enter characters (with spaces): ";
    getline(cin, s);

    queue<char> q;
    int freq[26] = {0}; // frequency array for lowercase letters

    for (char ch : s) {
        if (ch == ' ') continue; // skip spaces

        freq[ch - 'a']++;   // increase frequency
        q.push(ch);         // push into queue

        // remove from queue until front is non-repeating
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        // print result
        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }

    return 0;
}
