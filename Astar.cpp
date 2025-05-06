#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int priority;
    int x;
    int y;
    int cost;
    
    Node(int p, int x, int y, int cost) {
        this->priority = p;
        this->x = x;
        this->y = y;
        this->cost = cost;
    }

    bool operator <(const Node& other) const{
        return priority > other.priority;
    }
   

};
 int heuristic(int x1, int y1, int x2, int y2){
        return abs(x1-x2)+abs(y1-y2);
    }


int main(){
    int sx = 0, sy = 0, gx = 4, gy = 4;
    int n = 5, m = 5;
    vector<vector<int>> grid = {
        {0,1,0,0,0},
        {0,1,0,1,0},
        {0,0,0,1,0},
        {1,1,0,0,0},
        {0,0,0,1,0}
    };
    priority_queue<Node> pq;
    pq.push(Node(heuristic(sx,sy,gx,gy), sx, sy, 0));

    vector<vector<bool>> visited(n,vector<bool>(m,false));
    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};


    while(!pq.empty()){
        Node node = pq.top();
        pq.pop();
        int priority = node.priority, x = node.x, y = node.y, cost = node.cost;
        if(visited[x][y]) continue;
        visited[x][y] = true;

        if(x == gx && y == gy){
            cout<<"Reached goal with cost: "<<cost<<endl;
            return 0;
        }

        for(auto dir: directions){
            int nx = x + dir.first;
            int ny = y + dir.second;

            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0 && !visited[nx][ny]){
                int newCost = cost+1;
                int newPriority = newCost + heuristic(nx,ny,gx,gy);
                pq.push(Node(newPriority,nx,ny,newCost));   
            }
        }
            
    }

    cout<<"Goal not reachable!"<<endl;
    return 0;
}