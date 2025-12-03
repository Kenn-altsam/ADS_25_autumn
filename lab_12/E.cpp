#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long NO_EDGE_WEIGHT = 100000;
const long long INF = 1e18; 

struct Edge {
    int u, v;
    int weight;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Edge> edges;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int weight;
            cin >> weight;
            if (weight != NO_EDGE_WEIGHT) {
                edges.push_back({i, j, weight});
            }
        }
    }

    vector<long long> d(n + 1, 0); 
    vector<int> p(n + 1, -1);
    int x = -1;

    for (int i = 1; i <= n; ++i) {
        x = -1;
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;

            if (d[u] < INF) { 
                if (d[u] + weight < d[v]) {
                    d[v] = d[u] + weight;
                    p[v] = u;
                    x = v;
                }
            }
        }
    }

    if (x == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        int y = x;
        for (int i = 1; i <= n; ++i) {
            y = p[y];
        }

        vector<int> cycle;
        int current = y;

        do {
            cycle.push_back(current);
            current = p[current];
        } while (current != y);

        cycle.push_back(y);

        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << endl;
        for (int i = 0; i < cycle.size(); ++i) {
            cout << cycle[i] << (i == cycle.size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}