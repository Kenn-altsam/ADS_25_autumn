#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n, m, x;
    cin >> n >> m;

    map<int, int> my_map;
    vector<int> my_vector;

    for(int i = 0; i < n; i++){
        cin >> x;
        my_map[x]++;
    }

    for(int i = 0; i < m; i++){
        cin >> x;
        if(my_map[x]){
            my_vector.push_back(x);
            my_map[x]--;
        }
    }

    sort(my_vector.begin(), my_vector.end());

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << " ";
    }

    return 0;
}