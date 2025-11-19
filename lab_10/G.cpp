#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> color, parent;

int cycle_start = -1, cycle_end = -1;
bool found_cycle = false;

void dfs_find_cycle(int v) {
    color[v] = 1; 
    for(int to : g[v]) {
        if(found_cycle){
            return; 
        }
        if(color[to] == 0){
            parent[to] = v;
            dfs_find_cycle(to);
        }
        else if(color[to] == 1){
            // back edge -> cycle
            cycle_start = to;
            cycle_end = v;
            found_cycle = true;
            return;
        }
    }
    color[v] = 2; // fully processed
}

bool dfs_check(int v, int skip_u, int skip_v) {
    color[v] = 1;
    for(int to : g[v]){
        // skip the chosen edge
        if(v == skip_u && to == skip_v){
            continue;
        }

        if(color[to] == 0){
            if(dfs_check(to, skip_u, skip_v)){
                return true;
            }
        }
        else if
        (color[to] == 1){
            // found a back edge -> cycle
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool has_cycle_with_skip(int skip_u, int skip_v) {
    fill(color.begin(), color.end(), 0);
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            if (dfs_check(i, skip_u, skip_v)) return true;
        }
    }
    return false; // no cycle
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.assign(n + 1, {});

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    // 1. Find any cycle
    for(int i = 1; i <= n; i++) {
        if(color[i] == 0 && !found_cycle){
            dfs_find_cycle(i);
        }
    }

    if(!found_cycle) {
        // Already acyclic -> can remove <= 1 edge and still be acyclic
        cout << "YES\n";
        return 0;
    }

    // 2. Reconstruct one cycle as a list of edges
    vector<pair<int,int>> cycle_edges;
    cycle_edges.push_back({cycle_end, cycle_start}); // back edge

    int v = cycle_end;
    while(v != cycle_start){
        int u = parent[v];
        cycle_edges.push_back({u, v});
        v = u;
    }

    // 3. Try removing each edge of this cycle
    for(auto [u, v2] : cycle_edges){
        if(!has_cycle_with_skip(u, v2)){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
