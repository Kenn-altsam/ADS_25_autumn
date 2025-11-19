#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int n, m, query, left, right, x;
    vector<int> g[100005];
    bool used[100005];

    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        cin >> left >> right;
        g[left].push_back(right);
        g[right].push_back(left);
    }

    cin >> left >> right;

    queue<int> my_queue;

    my_queue.push(left);

    while(!my_queue.empty()){
        int v = my_queue.front();
        my_queue.pop();

        for(int to : g[v]){
            if(!used[to]){
                used[to] = 1;
                my_queue.push(to);
            }
        }
    }

    if(used[right]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}