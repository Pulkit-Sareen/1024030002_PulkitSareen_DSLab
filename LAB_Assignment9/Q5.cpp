#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinKey(vector<int>& key, vector<bool>& mstSet, int V) {
    int minKey = INT_MAX, index = -1;
    for (int i = 0; i < V; i++)
        if (!mstSet[i] && key[i] < minKey)
            minKey = key[i], index = i;
    return index;
}

int main() {
    int V = 5;

    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Prim's MST:\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " -- " << i << "  (Weight = " << graph[i][parent[i]] << ")\n";

    return 0;
}
