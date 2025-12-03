#include <iostream>
#include <vector>
using namespace std;

struct DSU {
    vector<int> parent, size;

    DSU(int n) : parent(n + 1), size(n + 1, 1){
        for(int i = 1; i <=n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b){
            return false;
        }
        if(size[a] < size[b]){
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);

    for(int i = 0; i < m; i++){
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    DSU dsu(n);

    vector<int> ans(n);
    vector<bool> active(n + 1, false);

    int components = 0;

    for(int v = n; v >= 1; v--){
        active[v] = true;
        components++;

        for(int u : g[v]){
            if(active[u]){
                if(dsu.unite(v, u)){
                    components--;
                }
            }
        }

        ans[v - 1] = components;
    }

    for(int i = 1; i < n; i++){
        cout << ans[i] << endl;
    }
    cout << 0;

    return 0;
}