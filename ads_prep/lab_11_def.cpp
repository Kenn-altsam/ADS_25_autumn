#include <iostream>
using namespace std;

typedef pair<int, int> PII;

int prim(int n, vector<vector<PII>> &adj, int start){
    priority_queue<PII> pq;
    vector<int> visited(n, false);

    pq.push({0, start});
    int sum = 0;

    while(!pq.empty()){
        PII it = pq.top();
        pq.pop();
        int weight = it.first;
        int node = it.second;

        if(visited[node] == true){
            continue;
        }

        visited[node] = true;
        sum += weight;

        for(PII it : adj[node]){
            int adjNode = it.first;
            int adjWeight = it.second;

            if(!visited[adjNode]){
                pq.push({adjWeight, adjNode});
            }
        }
    }
    return sum;
}

int main(){

    vector<vector<PII>> adj(4);

    adj[0].push_back({1, 4});
    adj[1].push_back({0, 4});

    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});
    
    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});

    adj[1].push_back({3, 3});
    adj[3].push_back({1, 3});

    adj[2].push_back({3, 5});
    adj[3].push_back({2, 5});

    cout << prim(4, adj, 0);

    return 0;
}