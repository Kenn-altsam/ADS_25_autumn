#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

    long long n, k, x, sum;

    vector<int> my_vector;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> x;
        my_vector.push_back(x);
    }

    long long left = 1;
    vector<int>::iterator it = max_element(my_vector.begin(), my_vector.end());

    long long max_val;

    if(it != my_vector.end()){
        max_val = *it;
    }

    long long right = max_val;
    long long ans, mid;

    while(left <= right){
        mid = left + (right - left) / 2;
        sum = 0;

        for(int i = 0; i < n; i++){
            sum += ceil((double)my_vector[i] / mid);
        }

        if(sum <= k){
            right = mid - 1;
            ans = mid;
        }
        else if(sum > k){
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}