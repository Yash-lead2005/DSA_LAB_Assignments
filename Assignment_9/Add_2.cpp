#include <iostream>
using namespace std;

struct Node {
    int dist;
    int x;
    int y;
};

class MinHeap {
public:
    Node heap[10000];
    int size;

    MinHeap() {
        size = 0;
    }

    void insert(Node n) {
        heap[size] = n;
        int i = size;
        size++;

        // bubble up
        while(i > 0 && heap[i].dist < heap[(i - 1) / 2].dist) {
            Node temp = heap[i];
            heap[i] = heap[(i - 1) / 2];
            heap[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }

    Node extractMin() {
        Node root = heap[0];
        heap[0] = heap[size - 1];
        size--;

        // bubble down
        int i = 0;
        while(true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int smallest = i;

            if(left < size && heap[left].dist < heap[smallest].dist)
                smallest = left;

            if(right < size && heap[right].dist < heap[smallest].dist)
                smallest = right;

            if(smallest == i) break;

            Node temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;

            i = smallest;
        }

        return root;
    }

    bool empty() {
        return size == 0;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    int grid[100][100];
    int distArr[100][100];

    // input grid
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            distArr[i][j] = 1000000000; // large value
        }

    MinHeap pq;

    distArr[0][0] = grid[0][0];
    pq.insert({distArr[0][0], 0, 0});

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!pq.empty()) {
        Node curr = pq.extractMin();
        int d = curr.dist;
        int x = curr.x;
        int y = curr.y;

        if(d != distArr[x][y]) continue;

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx >= 0 && ny >= 0 && nx < m && ny < n) {
                int newDist = d + grid[nx][ny];

                if(newDist < distArr[nx][ny]) {
                    distArr[nx][ny] = newDist;
                    pq.insert({newDist, nx, ny});
                }
            }
        }
    }

    cout << distArr[m-1][n-1] << endl;

    return 0;
}
