#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

typedef long long ll;

struct City {
    ll x, y;
};

vector<City> cities;
int N;

ll manhattan_distance(const City& c1, const City& c2) {
    return abs(c1.x - c2.x) + abs(c1.y - c2.y);
}

bool check(ll max_age) {
    if (N == 1) return true;

    vector<bool> visited(N, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == N - 1) {
            return true;
        }

        for (int v = 0; v < N; ++v) {
            if (!visited[v]) {
                ll dist = manhattan_distance(cities[u], cities[v]);
                
                if (dist <= max_age) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    return false;
}

int main() {

    if (!(cin >> N)) return 0;

    if (N == 1) {
        ll x, y;
        cin >> x >> y;
        cout << 0 << endl;
        return 0;
    }
    
    cities.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> cities[i].x >> cities[i].y;
    }

    ll L = 0; 
    ll R = 2000000000LL; 
    ll result = R;

    while (L <= R) {
        ll mid = L + (R - L) / 2;

        if (check(mid)) {
            result = mid; 
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    cout << result << endl;
    
    return 0;
}