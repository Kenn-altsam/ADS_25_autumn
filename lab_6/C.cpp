#include <iostream>
#include <vector> 
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main(){

    long long n, x;
    cin >> n;

    vector<long long> my_vector;

    for(int i = 0; i < n; i++){
        cin >> x;
        my_vector.push_back(x);
    }

    sort(my_vector.begin(), my_vector.end());
    long long minimum = INT_MAX;

    // getting minimum difference

    for(int i = 1; i <= n; i++){
        if(abs(my_vector[i] - my_vector[i - 1]) < minimum){
            minimum = abs(my_vector[i] - my_vector[i - 1]);
        }
    }

    for(int i = 1; i <= n; i++){
        if(abs(my_vector[i] - my_vector[i - 1]) == minimum){
            cout << my_vector[i - 1] << ' ' << my_vector[i] << ' ';
        }
    }

    return 0;
}