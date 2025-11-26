#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &visited) {
    visited[node] = 1;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(V, 0);
    int components = 0;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }

    cout << components << endl;
    return 0;
}
