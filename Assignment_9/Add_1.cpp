#include <iostream>
using namespace std;

int adj[100][100];    
int visited[100];     

int V, E;

void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    cin >> V >> E;

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    int components = 0;

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            components++;
            dfs(i);
        }
    }
    cout << components;

    return 0;
}
