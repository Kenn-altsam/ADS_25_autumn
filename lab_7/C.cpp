#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int first, second, x;
    cin >> first >> second;

    map<int, int> my_map;
    vector<int> result;

    for(int i = 0; i < first; i++){
        cin >> x;
        my_map[x]++;
    }

    for(int i = 0; i < second; i++){
        cin >> x;
        if(my_map[x]){
            result.push_back(x);
            my_map[x]--;
        }
    }

    sort(result.begin(), result.end());

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << ' ';
    }

    return 0;
}