#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    int adj[100][100] = {0};

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int start;
    cin >> start;

    bool visited[100] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return 0;
}
