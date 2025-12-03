#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<long long>> dist(n, vector<long long>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];

        x[i]--;
    }

    vector<bool> active(n, false);
    
    for (int k = 0; k < n; ++k) {
        int pivot = x[k]; 
        active[pivot] = true;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][pivot] + dist[pivot][j]);
            }
        }

        long long max_shortest_path = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (active[i] && active[j]) {
                    max_shortest_path = max(max_shortest_path, dist[i][j]);
                }
            }
        }

        cout << max_shortest_path << "\n";
    }

    return 0;
}