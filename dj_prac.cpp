#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

void dijkstra(int start, vector<vector<pii>> &graph, int V){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V,  false);
    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        for(auto &neighbor: graph[node]){
            int next_node = neighbor.first;
            int dist_node = neighbor.second;
            if(!visited[next_node] && distance + dist_node < dist[next_node]){
                dist[next_node] = distance + dist_node;
                pq.push({dist[next_node], next_node});
            }
        }
    }


    cout << "Shortest Cost : "<< endl;
    for(int i = 0; i < V;  i++){
        cout << "Node " << i << "->" << dist[i] << endl;
    }
}

int main(){
    int V = 4;
    vector<vector<pii>> graph(V);
    graph[0] = {{1, 2}, {3, 6}};
    graph[1] = {{0, 2}, {2, 3}, {3, 8}};
    graph[2] = {{1, 3}, {3, 5}};
    graph[3] = {{0, 6}, {1, 8}, {2, 5}};

    int start_node = 0;
    dijkstra(0,graph,V);

    return 0;

}