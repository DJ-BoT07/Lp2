#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};

bool compare(Edge a, Edge b){
    return a.w  < b.w;
}

int find(int x,vector<int> &parent){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x],parent);
}

void kruskal(int V, vector<Edge> &edges){
    sort(edges.begin(),edges.end(), compare);
    vector<int> parent(V);
    for(int i = 0; i < V;i++) parent[i] = i;


    int mstWeight = 0;
    cout << "Edges in MST:"<< endl;
    for(Edge e: edges){
        int a = find(e.u, parent);
        int b = find(e.v, parent);
        if(a !=  b){
            cout <<  e.u << "--" << e.v << " : " << e.w <<endl;
            mstWeight+= e.w;
            parent[a]= b; 
        }
    }

    cout << "Total  Weight : " << mstWeight << endl;
}


int main(){
    int V = 4;
    int E = 5;
    vector<Edge>  edges = {
        {0, 1, 10},  // Edge from vertex 0 to 1 with weight 10
        {0, 2, 6},   // Edge from vertex 0 to 2 with weight 6
        {0, 3, 5},   // Edge from vertex 0 to 3 with weight 5
        {1, 3, 15},  // Edge from vertex 1 to 3 with weight 15
        {2, 3, 4}    // Edge from vertex 2 to 3 with weight 4
    };

    kruskal(V,edges);
    return 0;
}