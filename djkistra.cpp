#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(vector<vector<pii>>& graph, int start) {
    int V = graph.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq; // (distance, node)
    vector<int> distances(V, INT_MAX);
    vector<bool> visited(V, false);

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (visited[current_node]) continue;
        visited[current_node] = true;

        for (auto& neighbor : graph[current_node]) {
            int next_node = neighbor.first;
            int weight = neighbor.second;

            if (!visited[next_node] && current_distance + weight < distances[next_node]) {
                distances[next_node] = current_distance + weight;
                pq.push({distances[next_node], next_node});
            }
        }
    }

    // Print results
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << " -> " << distances[i] << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<pii>> graph(V);
    graph[0] = {{1, 2}, {3, 6}};
    graph[1] = {{0, 2}, {2, 3}, {3, 8}};
    graph[2] = {{1, 3}, {3, 5}};
    graph[3] = {{0, 6}, {1, 8}, {2, 5}};

    int start_node = 0;
    dijkstra(graph, start_node);

    return 0;
}
