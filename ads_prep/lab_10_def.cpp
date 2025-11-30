#include <iostream>
using namespace std;

vector<int> bfs(int start, vector<vector<int>> &adj){
    queue<int> my_queue;
    vector<int> dist(adj.size(), 0);

    dist[start] = 0;
    my_queue.push(start);

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

    vector<vector<int>> adj {
        {1},
        {0, 2, 3},
        {1, 4, 5},
        {1, 4},
        {2, 3, 7},
        {2, 6},
        {5},
        {4}
    };

    vector<int> dist = bfs(0, adj);

    for(int i = 1; i < dist.size(); i++){
        if(dist[i] <= 2){
            cout << i << ' ';
        }
    }

    return 0;
}