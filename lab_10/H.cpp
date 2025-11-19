#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main(){

    int n, m, ans;
    char c[101][101];
    bool used[101][101];

    memset(used, 0, sizeof(used));

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(c[i][j] == '1' && !used[i][j]){
                ans++;
                queue<pair<int, int>> my_queue;
                my_queue.push({i, j});
                used[i][j] = 1;

                while(!my_queue.empty()){
                    pair<int, int> p = my_queue.front();
                    int left = p.first;
                    int right = p.second;
                    my_queue.pop();

                    if(left + 1 <= n && !used[left + 1][right] && c[left + 1][right] == '1'){
                        my_queue.push({left + 1, right});
                        used[left + 1][right] = 1;
                    }
                    if(left - 1 >= 1 && !used[left - 1][right] && c[left - 1][right] == '1'){
                        my_queue.push({left - 1, right});
                        used[left - 1][right] = 1;
                    }
                    if(right + 1 <= m && !used[left][right + 1] && c[left][right + 1] == '1'){
                        my_queue.push({left, right + 1});
                        used[left][right + 1] = 1;
                    }
                    if(right - 1 >= 1 && !used[left][right - 1] && c[left][right - 1] == '1'){
                        my_queue.push({left, right - 1});
                        used[left][right - 1] = 1;
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}