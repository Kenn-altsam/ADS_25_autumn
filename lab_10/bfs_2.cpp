#include <iostream>
using namespace std;

vector<int> bfs(int start, vector<vector<int>> &adj){
    vector<bool> visited(adj.size(), false);
    queue<int> my_queue;
    vector<int> dist(adj.size(), -1);

    visited[start] = true;
    my_queue.push(start);
    dist[start] = 0;

    while(!my_queue.empty()){
        int vertex = my_queue.front();
        my_queue.pop();

        for(int i = 0; i < adj[vertex].size(); i++){
            int neighbor = adj[vertex][i];
            if(!dist[neighbor]){
                dist[neighbor] = dist[vertex] + 1;
                my_queue.push(neighbor);
            }
        }
    }
    return dist;
}

int main(){

    vector<vector<int>> adj = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 4},
        {1, 3},
        {2, 3}
    };

    bfs(0, adj);

    return 0;
}