#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int n, m, query, left, right;
    vector<int> g[5005];
    vector<int> type(5005, 0);
    vector<int> path(40005);

    cin >> n >> m >> query;

    for(int i = 1; i <= m; i++){
        cin >> left >> right;
        g[left].push_back(right);
        g[right].push_back(left);
    }

    for(int i = 1; i <= query; i++){
        cin >> left >> right;
        if(left == 1){
            type[right] = 1;
        }
        else{
            queue<int> my_queue;
            vector<int> d(n + 2, -1);

            my_queue.push(right);
            d[right] = 0;
            int ans = -1;

            while(!my_queue.empty()){
                int v = my_queue.front();
                my_queue.pop();

                if(type[v] == 1){
                    ans = d[v];
                    break;
                }

                for(int to: g[v]){
                    if(d[to] == -1){
                        d[to] = d[v] + 1;
                        my_queue.push(to);
                    }
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}