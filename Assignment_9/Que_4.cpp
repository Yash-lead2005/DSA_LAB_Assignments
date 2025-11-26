#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int graph[100][100];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];

    int src;
    cin >> src;

    int dist[100];
    int visited[100] = {0};

    for(int i = 0; i < n; i++)
        dist[i] = 999999;

    dist[src] = 0;

    for(int count = 0; count < n - 1; count++) {
        int u = -1;

        for(int i = 0; i < n; i++)
            if(!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = 1;

        for(int v = 0; v < n; v++) {
            if(graph[u][v] > 0 && !visited[v]) {
                if(dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    cout << "Shortest distances from source " << src << ":" << endl;
    for(int i = 0; i < n; i++)
        cout << src << " -> " << i << " = " << dist[i] << endl;

    return 0;
}
