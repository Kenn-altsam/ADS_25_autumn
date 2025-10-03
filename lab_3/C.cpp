#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){

    int n, q, x, l1, r1, l2, r2;

    cin >> n >> q;

    vector<int> my_vector;
    map<int, int> my_map;

    for(int i = 0; i < n; i++){
        cin >> x;
        my_vector.push_back(x);
        my_map[x]++;
    }

    sort(my_vector.begin(), my_vector.end());

    for(int i = 0; i < q; i++){
        cin >> l1 >> r1 >> l2 >> r2;

        int left = max(l1, l2);
        int right = min(r1, r2);
        
        vector<int>::iterator first_lower = lower_bound(my_vector.begin(), my_vector.end(), l1);
        vector<int>::iterator first_upper = upper_bound(my_vector.begin(), my_vector.end(), r1);

        vector<int>::iterator second_lower = lower_bound(my_vector.begin(), my_vector.end(), l2);
        vector<int>::iterator second_upper = upper_bound(my_vector.begin(), my_vector.end(), r2);

        int first_interval = first_upper - first_lower;
        int second_interval = second_upper - second_lower;

        int third_interval = 0;
        if(left <= right){
            third_interval = upper_bound(my_vector.begin(), my_vector.end(), right) - lower_bound(my_vector.begin(), my_vector.end(), left);
        }

        cout << first_interval + second_interval - third_interval << endl;
    }

    return 0;
}

