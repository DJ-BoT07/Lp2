#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>>& graph, int edge1, int edge2) {
    graph[edge1][edge2] = 1;
    graph[edge2][edge1] = 1;
}

bool safeToAssign(int node, int col, vector<vector<int>>& graph, vector<int>& color) {
    for (int k = 0; k < graph.size(); k++) {
        if (graph[node][k] == 1 && color[k] == col) {
            return false;
        }
    }
    return true;
}

bool solve(int node, int m, vector<vector<int>>& graph, vector<int>& color) {
    if (node == graph.size()) return true;

    for (int c = 1; c <= m; c++) {
        if (safeToAssign(node, c, graph, color)) {
            color[node] = c;
            if (solve(node + 1, m, graph, color)) return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>> &graph, int m){
    int V = graph.size();
    vector<int> color(V,0);
    
    bool ans = solve(0,m,graph, color);
    for(int i : color){
        cout << i << " ";
    }
    return ans;
}

int main() {
    int m = 3, v = 5;
    vector<vector<int>> graph(v, vector<int>(v, 0));

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    if (graphColoring(graph, m))
        cout << "Coloring possible\n";
    else
        cout << "Coloring not possible\n";
}