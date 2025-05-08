#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v){
    graph[u][v] = 1;
    graph[v][u] = 1;
}

bool isSafeToAssign(int node,int m,vector<vector<int>>& graph, vector<int> &color){
    for(int k = 0; k < graph.size();  k++){
        if(graph[node][k] == 1 && color[k] == m){
            return false;
        }
    }

    return true;
}

bool solve(int node,int m,vector<vector<int>> &graph, vector<int> &color){
    if(node == graph.size())  return true;

    for(int c = 1; c <= m; c++){
        if(isSafeToAssign(node,c,graph, color)){
            color[node] = c;
            if(solve(node+1, m,graph, color)) return true;
            color[node] = 0;
        }
    }

    return false;
}

bool isGraphColoring(vector<vector<int>>& graph, int m){
    int V = graph.size();
    vector<int> color(V,0);

    bool ans = solve(0, m, graph,  color);
    for(int i :  color){
        cout <<  i << " ";
    }
    return ans;
}

int main(){
    int V = 5;
    int m = 2;

    vector<vector<int>> graph(V, vector<int>(V,0));

    addEdge(graph, 0,1);
    addEdge(graph,0,2);
    addEdge(graph ,0 ,3);
    addEdge(graph, 2,4);
    addEdge(graph, 3,4);

    if(isGraphColoring(graph,m)) cout << "Coloring is Possible\n";
    else cout << "Not Possible" << endl;
}