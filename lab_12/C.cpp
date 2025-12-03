#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 405;

int graph[MAXN][MAXN];
int dist[MAXN]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }

    for (int i = 1; i <= n; i++) {
        dist[i] = -1;
    }

    queue<int> q;

    dist[1] = 0;
    q.push(1);

    int target_edge_type = 1 - graph[1][n];

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == n) {
            cout << dist[n] << endl;
            return 0;
        }

        for (int v = 1; v <= n; v++) {
            if (u != v && graph[u][v] == target_edge_type && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << -1 << endl;

    return 0;
}