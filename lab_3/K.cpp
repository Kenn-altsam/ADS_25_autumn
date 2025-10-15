// find the smallest subarray with sum >= k

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main(){

    int n, k, x;

    cin >> n >> k;

    int my_array[n];

    for(int i = 0; i < n; i++){
        cin >> x;
        my_array[i] = x;
    }

    int left = 0, ans = INT_MAX, right, sum = 0;

    for(int i = 0; i < n; i++){
        right = i;
        sum += my_array[right];

        while(sum >= k){
            ans = min(ans, right - left + 1);
            sum -= my_array[left];
            left++;
        }
    }

    cout << ans;

    return 0;
}