#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

    int n, m, x;
    cin >> n >> m;

    int my_array[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> x;
            my_array[i][j] = x;
        }
    }

    for(int j = 0; j < m; j++){
        vector<int> col;
        for(int i = 0; i < n; i++){
            col.push_back(my_array[i][j]);
        }

        sort(col.begin(), col.end(), greater<int>());

        for(int i = 0; i < n; i++){
            my_array[i][j] = col[i];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << my_array[i][j] << ' '; 
        }
        cout << endl;
    }


    return 0;
}