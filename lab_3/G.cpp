// Please, help him find the least possible capacity of the bag to deliver all gifts during no more than f flights.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

    long long n, k, x, sum;

    vector<int> my_vector;

    cin >> n >> k;

    for(int i = 0; i < n; i++){ // getting the number of children in each island
        cin >> x;
        my_vector.push_back(x);
    }

    long long left = 1;
    vector<int>::iterator it = max_element(my_vector.begin(), my_vector.end()); // get the max element in the vector

    long long max_val;

    if(it != my_vector.end()){ // if the max value is in the vector, set max_val to *it
        max_val = *it;
    }

    long long right = max_val; // right is equal to max_val, and the left is 1
    long long ans, mid;

    while(left <= right){
        mid = left + (right - left) / 2;
        sum = 0;

        for(int i = 0; i < n; i++){
            sum += ceil((double)my_vector[i] / mid); // sum the number of flights
        }

        if(sum <= k){ // if the number of flights is less or equal to k, search forward to find the minimum
            right = mid - 1; // and save the result to the ans 
            ans = mid;
        }
        else if(sum > k){ // if the sum is not enough, go forward and search with the shifted left 
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}