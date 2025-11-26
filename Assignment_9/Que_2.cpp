#include <iostream>
using namespace std;

int adj[100][100];
bool visited[100];

void dfs(int node, int n) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int start;
    cin >> start;

    for (int i = 0; i < n; i++) 
        visited[i] = false;

    cout << "DFS: ";
    dfs(start, n);

    return 0;
}
