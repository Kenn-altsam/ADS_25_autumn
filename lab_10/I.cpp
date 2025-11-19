#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);

    for(int k = 0; k < m; k++){
        int i, j;
        cin >> i >> j;
        g[i].push_back(j);
        indeg[j]++;
    }

    queue<int> q;

    // push all quests that have no prerequisites
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    vector<int> order;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        order.push_back(v);

        for(int to : g[v]){
            indeg[to]--;
            if(indeg[to] == 0){
                q.push(to);
            }
        }
    }

    if((int)order.size() != n){
        cout << "Impossible\n";
    }
    else{
        cout << "Possible\n";
        for(int x : order) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
