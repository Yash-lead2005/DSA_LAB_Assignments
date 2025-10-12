#include <iostream>
#include <queue>
using namespace std;

int countStudents(int students[], int sandwiches[], int n) {
    queue<int> q;

    for (int i = 0; i < n; i++)
        q.push(students[i]);

    int i = 0;  
    int count = 0;

    while (!q.empty() && count < q.size()) {
        if (q.front() == sandwiches[i]) {
            q.pop();
            i++;
            count = 0;
        } else {
            q.push(q.front());
            q.pop();
            count++;
        }
    }

    return q.size();
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int students[100], sandwiches[100]; 

    cout << "Enter student preferences (0 or 1): ";
    for (int i = 0; i < n; i++)
        cin >> students[i];

    cout << "Enter sandwich stack (0 or 1): ";
    for (int i = 0; i < n; i++)
        cin >> sandwiches[i];

    int result = countStudents(students, sandwiches, n);
    cout << "Number of students unable to eat lunch: " << result << endl;

    return 0;
}
