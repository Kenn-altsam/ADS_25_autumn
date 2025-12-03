#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<long long> d(n);
    long long sum = 0;
    long long min_sum = LLONG_MAX;

    for(int i = 0; i < n; i++){
        cin >> d[i];
        sum += d[i];
        min_sum = min(min_sum, d[i]);
    }

    cout << sum + (n - 2) * min_sum;

    return 0;
}