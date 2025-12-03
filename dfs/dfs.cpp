#include <iostream>
using namespace std;

void dfs(int start, vector<vector<int>> &adj, vector<int> &visited, vector<int> &order){
    
    visited[start] = true;

    order.push_back(start);

    for(int i = 0; i < adj[start].size(); i++){
        int vertex = adj[start][i];
        if(!visited[vertex]){
            dfs(vertex, adj, visited, order);
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

    vector<int> visited(adj.size(), 0);
    vector<int> order;

    dfs(0, adj, visited, order);

    for(int i = 0; i < order.size(); i++){
        cout << order[i] << ' ';
    }

    return 0;
}