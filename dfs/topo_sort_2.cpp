#include <iostream>
using namespace std;

void topo_dfs(int start, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &order){
    visited[start] = true;

    for(int i = 0; i < adj[start].size(); i++){
        int vertex = adj[start][i];
        if(!visited[vertex]){   
            topo_dfs(vertex, adj, visited, order);
        }
    }

    order.push_back(start);
}

void topo_sort(vector<vector<int>> &adj){
    vector<bool> visited(adj.size(), false);
    vector<int> order;

    for(int i = 0; i < adj.size(); i++){
        if(!visited[i]){
            topo_dfs(i, adj, visited, order);
        }
    }

    reverse(order.begin(), order.end());

    for(int i = 0; i < order.size(); i++){
        cout << order[i] << ' ';
    }
}

int main(){

    vector<vector<int>> adj = {
        {}, 
        {},
        {3},
        {1},
        {0, 1},
        {0, 2}
    };

    topo_sort(adj);

    return 0;
}