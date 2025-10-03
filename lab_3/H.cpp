#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n, m, x, sum = 0;

    cin >> n >> m;

    vector<int> ends;

    for(int i = 0; i < n; i++){ // 3 7
        cin >> x;
        sum += x;
        ends.push_back(sum);
    }

    vector<int> mistakes;
    for(int i = 0; i < m; i++){
        cin >> x;
        vector<int>::iterator it = lower_bound(ends.begin(), ends.end(), x);
        int index = it - ends.begin();
        mistakes.push_back(index);
    }

    for(int i = 0; i < m; i++){
        cout << mistakes[i] + 1 << endl;
    }

    return 0;
}