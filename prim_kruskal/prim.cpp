#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> PII; 

int prim(int n, vector<vector<PII>> &adj, int start = 0){
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    vector<int> visited(n, false);

    pq.push({0, start}); // weight, node

    int sum = 0;

    while(!pq.empty()){
        PII it = pq.top();
        pq.pop();
        int weight = it.first;
        int node = it.second;

        if(visited[node] == true){
            continue;
        }

        visited[node] = 1;
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

    cout << prim(4, adj, 0);

    return 0;
}