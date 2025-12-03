#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    int weight;
};

vector<long long> dijkstra(int n, int start_node, const vector<vector<Edge>>& adj) {
    vector<long long> dist(n + 1, INF);
    dist[start_node] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start_node});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            if (dist[u] + edge.weight < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }
    return dist;
}

int main() {

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<Edge>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start_node, merchant, pharmacy, grandmother;
    cin >> start_node >> merchant >> pharmacy >> grandmother;

    vector<long long> distFromStart = dijkstra(n, start_node, adj);
    vector<long long> distFromMer = dijkstra(n, merchant, adj);
    vector<long long> distFromPhar = dijkstra(n, pharmacy, adj);

    long long path1 = INF;
    if (distFromStart[merchant] != INF && 
        distFromMer[pharmacy] != INF && 
        distFromPhar[grandmother] != INF) {
        path1 = distFromStart[merchant] + distFromMer[pharmacy] + distFromPhar[grandmother];
    }

    long long path2 = INF;
    if (distFromStart[pharmacy] != INF && 
        distFromPhar[merchant] != INF && 
        distFromMer[grandmother] != INF) {
        path2 = distFromStart[pharmacy] + distFromPhar[merchant] + distFromMer[grandmother];
    }

    long long ans = min(path1, path2);

    if (ans >= INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}