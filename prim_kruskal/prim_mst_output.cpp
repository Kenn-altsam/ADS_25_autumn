#include <iostream>
using namespace std;

typedef pair<int, pair<int, int>> PII;

vector<pair<int, int>> prim(int n, vector<vector<pair<int, int>>> &adj, int start){
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    vector<int> visited(n, false);
    vector<pair<int, int>> mst;

    pq.push({0, {start, -1}}); // weight, node
    int sum = 0;

    while(!pq.empty()){
        PII it = pq.top();
        pq.pop();
        int weight = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if(visited[node] == true){
            continue;
        }

        visited[node] = true;
        if(parent != -1){
            mst.push_back({parent, node});
        }
        sum += weight;    

        for(pair<int, int> it : adj[node]){
            int adjNode = it.first;
            int adjWeight = it.second;

            if(!visited[adjNode]){
                pq.push({adjWeight, {adjNode, node}});
            }
        }
    }

    return mst;
}

int main(){

    vector<vector<pair<int, int>>> adj(4);

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

    vector<pair<int, int>> mst = prim(4, adj, 0);

    for(pair<int, int> it : mst){
        cout << it.first << ' ' << it.second << endl;
    }

    return 0;
}