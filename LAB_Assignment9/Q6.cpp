#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinDist(vector<int>& dist, vector<bool>& visited, int V) {
    int minVal = INT_MAX, index = -1;
    for (int i = 0; i < V; i++)
        if (!visited[i] && dist[i] < minVal)
            minVal = dist[i], index = i;
    return index;
}

int main() {
    int V = 5;

    int graph[5][5] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    int src = 0;
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinDist(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && 
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Dijkstra's Shortest Path from source 0:\n";
    for (int i = 0; i < V; i++)
        cout << "0 -> " << i << " = " << dist[i] << endl;

    return 0;
}
