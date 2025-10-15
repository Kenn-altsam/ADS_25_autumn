// Print the minimum number K such that Robin Hood can steal all of the N golden bars within the limit of H hours.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

    int n, k, x, sum;

    cin >> n >> k;

    vector<int> my_vector;

    for(int i = 0; i < n; i++){
        cin >> x;
        my_vector.push_back(x);
    }

    vector<int>::iterator max_it = max_element(my_vector.begin(), my_vector.end()); // get the max

    int max_val;

    if(max_it != my_vector.end()){
        max_val = *max_it; // get the max val
    }

    int left = 1, right = max_val, mid, ans;

    while(left <= right){
        mid = left + (right - left) / 2;
        sum = 0;

        for(int i = 0; i < n; i++){
            sum += ceil((double)my_vector[i] / mid); // get the sum of how many hours are needed
        }

        if(sum > k){ // if the sum is less than k, then must need to find the higher k, otherwise we wouldn't be on time
            left = mid + 1;
        }
        else if(sum <= k){ // if the sum is greater than k, then we might still find the less k for the minimum
            ans = mid;
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}