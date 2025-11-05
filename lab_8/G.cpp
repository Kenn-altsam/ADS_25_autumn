#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cstdint>
using namespace std;

const long long mod1 = 1e9 + 7;
const int power1 = 31;
const long long mod2 = 1e9 + 9;
const int power2 = 37;

pair<vector<long long>, vector<long long>> prefix_hash(string my_string, long long mod, int power){
    int n = my_string.size(); 
    vector<long long> hashh(n + 1, 0);
    vector<long long> powers(n + 1, 1);

    for(int i = 0; i < n; i++){
        hashh[i + 1] = (hashh[i] * power + (my_string[i] - 'a' + 1)) % mod;
        powers[i + 1] = (powers[i] * power) % mod;
    }

    return {hashh, powers};
}

long long get_hash(const vector<long long> &hashh, const vector<long long> &powers, int left, int right, long long mod){
    long long result = (hashh[right] - hashh[left] * powers[right - left]) % mod;
    if (result < 0){
        result += mod;
    }
    return result;
}

int main(){

    string my_string;
    int n, left, right;

    cin >> my_string >> n;
    unordered_map<uint64_t, int> my_map;

    auto p1 = prefix_hash(my_string, mod1, power1);
    vector<long long> hashh1 = p1.first;
    vector<long long> powers1 = p1.second; 
    auto p2 = prefix_hash(my_string, mod2, power2);
    vector<long long> hashh2 = p2.first;
    vector<long long> powers2 = p2.second;

    for(int i = 0; i < my_string.size(); i++){
        for(int j = i + 1; j <= my_string.size(); j++){
            long long x1 = get_hash(hashh1, powers1, i, j, mod1);
            long long x2 = get_hash(hashh2, powers2, i, j, mod2);
            uint64_t key = ((uint64_t)x1 << 32) ^ (uint64_t)x2;
            my_map[key]++;
        }
    }

    for(int i = 1; i <= n; i++){
        cin >> left >> right;
        left--; // Converts l from 1-indexed to 0-indexed
        long long x1 = get_hash(hashh1, powers1, left, right, mod1);
        long long x2 = get_hash(hashh2, powers2, left, right, mod2);

        uint64_t combine = ((uint64_t)x1 << 32) ^ ((uint64_t)x2);
        cout << my_map[combine] << endl;
    }

    return 0;
}