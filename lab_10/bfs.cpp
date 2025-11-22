#include <iostream>
using namespace std;

// void bfs(int start, vector<vector<int>> adj){
//     vector<bool> visited(adj.size(), false);
//     queue<int> my_queue;

//     visited[start] = true;
//     my_queue.push(start);

//     while(!my_queue.empty()){
//         int vertex = my_queue.front();
//         my_queue.pop();
//         cout << vertex << ' ';

//         for(int i = 0; i < adj[vertex].size(); i++){
//             int neighbor = adj[vertex][i];
//             if(!visited[neighbor]){
//                 visited[neighbor] = true;
//                 my_queue.push(neighbor);
//             }
//         }
//     }
// }

void bfs(int start, vector<vector<int>> &adj){
    vector<bool> visited(adj.size(), false);
    queue<int> my_queue;

    visited[start] = true;
    my_queue.push(start);

    while(!my_queue.empty()){
        int vertex = my_queue.front();
        my_queue.pop();

        for(int i = 0; i < adj[vertex].size(); i++){
            int neighbor = adj[vertex][i];
            if(!visited[neighbor]){
                visited[neighbor] = true;
                my_queue.push(neighbor);
            }
        }
    }
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