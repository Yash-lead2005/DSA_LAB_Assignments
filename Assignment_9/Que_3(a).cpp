#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cost[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    int selected[100] = {0};
    selected[0] = 1;

    int total = 0;

    cout << "MST (Prim):" << endl;

    for (int edges = 0; edges < n - 1; edges++) {
        int u = -1, v = -1, minW = 999999;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] != 0 && cost[i][j] < minW) {
                        minW = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << u << " - " << v << " = " << minW << endl;
        total += minW;
        selected[v] = 1;
    }

    cout << "Total Weight = " << total << endl;

    return 0;
}
