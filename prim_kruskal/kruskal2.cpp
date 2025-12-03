#include <iostream>
using namespace std;

typedef pair<int, int> PII;

class DSU{
    vector<int> parent, rank;

public:
    DSU(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    void union_set(int u, int v){
        int ult_u = find(u);
        int ult_v = find(v);

        if(ult_u == ult_v){
            return;
        }
        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_v] < rank[ult_u]){
            parent[ult_v] = ult_u;
        }
        else{
            parent[ult_v] = ult_u;
            ult_u++;
        }
    }
};

int kruskal(int n, vector<vector<PII>> &adj){
    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < n; i++){
        for(PII it : adj[i]){
            int weight = it.second;
            int adjNode = it.first;
            int node = i;

            edges.push_back({weight, {node, adjNode}});
        }
    }

    sort(edges.begin(), edges.end());

    int sum = 0;
    DSU dsu(n);

    for(pair<int, pair<int, int>> it : edges){
        int weight = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(dsu.find(u) != dsu.find(v)){
            sum += weight;
            dsu.union_set(u, v);
        }
    }
    return sum;
}

int main(){

    vector<vector<PII>> adj(4);

    adj[0].push_back({1, 13});
    adj[0].push_back({2, 12});

    adj[1].push_back({0, 13});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 14});

    adj[2].push_back({0, 12});
    adj[2].push_back({1, 3});
    adj[2].push_back({3, 9});

    adj[3].push_back({1, 14});
    adj[3].push_back({2, 9});

    cout << kruskal(4, adj);

    return 0;
}