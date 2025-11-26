#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
    Edge *next;
};

void insertEdge(Edge* &head, int u, int v, int w) {
    Edge *newNode = new Edge;
    newNode->u = u;
    newNode->v = v;
    newNode->w = w;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Edge *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void sortEdges(Edge* &head) {
    if (!head) return;

    for (Edge *i = head; i->next != NULL; i = i->next) {
        for (Edge *j = head; j->next != NULL; j = j->next) {
            if (j->w > j->next->w) {
                // swap data only
                int tu = j->u, tv = j->v, tw = j->w;

                j->u = j->next->u;
                j->v = j->next->v;
                j->w = j->next->w;

                j->next->u = tu;
                j->next->v = tv;
                j->next->w = tw;
            }
        }
    }
}

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

int main() {
    int n, m;
    cin >> n >> m;

    Edge *head = NULL;


    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        insertEdge(head, u, v, w);
    }


    sortEdges(head);

  
    int parent[100], rank[100];
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    cout << "MST (Kruskal):\n";

    int totalWeight = 0;
    Edge *temp = head;


    while (temp != NULL) {
        int pu = findParent(parent, temp->u);
        int pv = findParent(parent, temp->v);

        if (pu != pv) {
            cout << temp->u << " - " << temp->v << " = " << temp->w << "\n";
            totalWeight += temp->w;
            unionSet(parent, rank, pu, pv);
        }
        temp = temp->next;
    }

    cout << "Total Weight = " << totalWeight << endl;

    return 0;
}
