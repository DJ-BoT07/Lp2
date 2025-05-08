#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<vector<int>> adj;
public:
    Graph(int V){
        adj.resize(V);
    }

    void addEdge(int u, int v){
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    void dfsHelper(int start,vector<bool> &visited){
        visited[start] = true;
        cout << start << " ";
        for(int neighbour: adj[start]){
            if(!visited[neighbour]){
                dfsHelper(neighbour, visited);
            }
        }
    }

    void dfs(int node){
        vector<bool> visited(adj.size(),false);
        dfsHelper(node,visited);
    }

    void bfs(int start){
        vector<bool> visited(adj.size(),false);
        queue<int>  q;
        visited[start] = true;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            cout<<node<<' ';
            q.pop();
            for(int neighbour: adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }
};

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << "DFS: "; g.dfs(0);
    cout << "\nBFS: "; g.bfs(0);
}