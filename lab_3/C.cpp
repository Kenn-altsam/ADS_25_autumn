#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n, q, x, l1, r1, l2, r2;

    cin >> n >> q;

    vector<int> my_vector;

    for(int i = 0; i < n; i++){
        cin >> x;
        my_vector.push_back(x);
    }

    sort(my_vector.begin(), my_vector.end());

    for(int i = 0; i < q; i++){
        cin >> l1 >> r1 >> l2 >> r2;
        
        first_lower = lower_bound(my_vector.begin(), my_vector.end(), l1);
        
    }

    return 0;
}

