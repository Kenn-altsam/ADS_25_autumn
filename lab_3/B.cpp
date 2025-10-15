#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Find the sum of all elements in the vector
long long summa(vector<int> my_vector){
    long long my_sum = 0;
    for(int i = 0; i < my_vector.size(); i++){
        my_sum += my_vector[i];
    }

    return my_sum;
}

int main(){

    int n, k, x;
    long long sum;

    cin >> n >> k; // number of houses and number of blocks

    vector<int> my_vector;

    for(int i = 0; i < n; i++){ // Number of ghouls in each house
        cin >> x;
        my_vector.push_back(x);
    }

    long long left = *max_element(my_vector.begin(), my_vector.end()); // The smallest possible max-sum per block  must be at least the maximum element (a single house)
    long long right = summa(my_vector); // The largest possible max-sum per block is the sum of all ghouls (if we make one block)      
    long long ans = right;
    long long mid, block;

    if(k >= n){ // if k >= n, we just need to print the house with max num, and each house would be a block 
        cout << left;
        return 0;
    }

    while(left <= right){
        mid = left + (right - left) / 2;
        sum = 0;
        block = 1;
        
        for(int i = 0; i < n; i++){
            if(sum + my_vector[i] > mid){ // it doesn't fit, so we open the new block 
                block++;
                sum = 0;
            }
            sum += my_vector[i];
        }

        if(block <= k){
            ans = mid;
            right = mid - 1;
        }
        else{ // If the number of blocks > K → mid is too small.
            left = mid + 1;
        }
    }  

    cout << ans;

    return 0;
}