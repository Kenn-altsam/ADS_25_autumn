#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int n, m, ans, left, right;
    vector<int> g[100005];
    int children[100005];
    bool used[100005];

    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        cin >> left >> right;
        g[left].push_back(right);
        g[right].push_back(left);
        children[left]++;
    }

    for(int i = 1; i <= n; i++){
        if(!used[i]){
            queue<int> my_queue;
            my_queue.push(i);
            used[i] = 1;
            ans++;
            
            while(!my_queue.empty()){
                int v = my_queue.front();
                my_queue.pop();

                for(int to : g[v]){
                    if(!used[to]){
                        if(children[v] < children[to]){
                            ans++;
                        }
                        used[to] = 1;
                        my_queue.push(to);
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}