#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii; // (weight, node)

int primMST(int V, vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(V, false);
    int totalCost = 0;

    
    pq.push({0, 0}); // (weight, node)

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) continue;

        visited[node] = true;
        totalCost += weight;

        for (auto& edge : adj[node]) {
            int neighbor = edge.first;
            int edgeWeight = edge.second;
            if (!visited[neighbor]) {
                pq.push({edgeWeight, neighbor}); // (weight, node)
            }
        }
    }
    return totalCost;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    // Example edges: {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 2, 1}, {1, 2, 1},
        {2, 3, 2}, {3, 4, 1}, {4, 2, 2}
    };

    for (auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int result = primMST(V, adj);
    cout << "Total cost of MST: " << result << endl;

    return 0;
}
