#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int n, m, query, left, right, x;
    vector<int> g[5005];
    vector<int> type(5005, 0);
    vector<int> path(40005);

    cin >> n >> query;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            if(x == 1){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for(int i = 1; i <= query; i++){
        int y, z;
        cin >> x >> y >> z;

        bool ok1, ok2, ok3;
        ok1 = ok2 = ok3 = 0;
        
        for(int to : g[x]){
            if(to == y){
                ok1 = 1;
            }
            if(to == z){
                ok2 = 1;
            }
        }

        for(int to : g[y]){
            if(to == z){
                ok3 = 1;
            }
        }
        if(ok1 && ok2 && ok3){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}