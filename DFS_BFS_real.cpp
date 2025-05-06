#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    vector<Node*> neighbors;

    Node(int val) : data(val) {}
};

class Graph {
    vector<Node*> nodes;

public:
    Graph(int V) {
        for (int i = 0; i < V; i++) {
            nodes.push_back(new Node(i));
        }
    }

    void addEdge(int u, int v) {
        nodes[u]->neighbors.push_back(nodes[v]);
        nodes[v]->neighbors.push_back(nodes[u]); // undirected
    }

    void dfsUtil(Node* node, vector<bool>& visited) {
        visited[node->data] = true;
        cout << node->data << " ";
        for (Node* neighbor : node->neighbors) {
            if (!visited[neighbor->data])
                dfsUtil(neighbor, visited);
        }
    }

    void dfs(int start) {
        vector<bool> visited(nodes.size(), false);
        dfsUtil(nodes[start], visited);
    }

    void bfs(int start) {
        vector<bool> visited(nodes.size(), false);
        queue<Node*> q;
        visited[start] = true;
        q.push(nodes[start]);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            cout << node->data << " ";
            for (Node* neighbor : node->neighbors) {
                if (!visited[neighbor->data]) {
                    visited[neighbor->data] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    ~Graph() {
        for (Node* node : nodes) {
            delete node;
        }
    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << "DFS (recursive): ";
    g.dfs(0);
    cout << "\nBFS: ";
    g.bfs(0);

    return 0;
}
