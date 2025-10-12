// #include<iostream>
// using namespace std;
// #define MAXLEN 4
// class Queue{

//     int Que[MAXLEN];
//     int front =-1;
//     int rear = -1;
// };

// int main(){
//     Queue qt;

//     return 0;
// }









#include <iostream>
#include<queue>
#include <unordered_map>
using namespace std;

int main() {
    queue<char>q;
    q.push(a);
    q.push(a);
    q.push(b);
    q.push(c);
    unordered_map<char, int> freq;

    
    for (int i = 0; i < 4; i++) {
        freq[q[i]]++;
    }

    
    for (int i = 0; i < 4; i++) {
        if (freq[q[i]] == 1) {
            cout << q[i] << endl;
            break;
        }
    }
    return 0;
}

