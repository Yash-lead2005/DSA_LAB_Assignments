#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int parent[], int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unionSet(int parent[], int rank[], int a, int b) {
    int pa = findParent(parent, a);
    int pb = findParent(parent, b);

    if (pa != pb) {
        if (rank[pa] < rank[pb]) parent[pa] = pb;
        else if (rank[pb] < rank[pa]) parent[pb] = pa;
        else { parent[pb] = pa; rank[pa]++; }
    }
}

void sortEdges(Edge e[], int m) {
    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < m - i - 1; j++)
            if (e[j].w > e[j+1].w)
                swap(e[j], e[j+1]);
}

int main() {
    int n, m;
    cin >> n >> m;

    Edge e[1000];
    for (int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;

    sortEdges(e, m);

    int parent[100], rank[100] = {0};
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int totalWeight = 0;
    cout << "MST (Kruskal):" << endl;

    for (int i = 0; i < m; i++) {
        int pu = findParent(parent, e[i].u);
        int pv = findParent(parent, e[i].v);

        if (pu != pv) {
            cout << e[i].u << " - " << e[i].v << " = " << e[i].w << endl;
            totalWeight += e[i].w;
            unionSet(parent, rank, pu, pv);
        }
    }

    cout << "Total Weight = " << totalWeight << endl;
    return 0;
}
