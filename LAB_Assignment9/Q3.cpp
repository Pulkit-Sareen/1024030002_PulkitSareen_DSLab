#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int v : adj[node])
        if (!visited[v])
            DFS(v, adj, visited);
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };

    vector<bool> visited(4, false);

    cout << "DFS Traversal: ";
    DFS(0, adj, visited);

    return 0;
}
