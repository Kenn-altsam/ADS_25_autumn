#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int n, m, left, right, c;  
    long long ans = 0;

    cin >> n >> m;

    vector<pair<int, int>> start[n + 5], finish[n + 5];

    for(int i = 1; i <= m; i++){
        cin >> left >> right >> c;

        start[left].push_back({right, c});
        finish[right].push_back({left, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > my_pq;

    for(int i = 1; i < n; i++){
        for(auto p : start[i]){
            my_pq.push({p.second, p.first});
        }
        
        while(!my_pq.empty() && my_pq.top().second <= i){
            my_pq.pop();
        }

        if(my_pq.empty()){
            cout << '0' << endl;
            return 0;
        }

        ans += my_pq.top().first;
    }

    cout << ans;

    return 0;
}