#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <cstdint>
#include <climits>
using namespace std;

const long long mod1 = 1e9 + 7;
const long long mod2 = 1e9 + 9;
const int power1 = 31;
const int power2 = 37;

pair<vector<long long>, vector<long long>> prefix_hash(const string &my_string, long long mod, int power){
    int n = my_string.size();
    vector<long long> hashh(n + 1, 0), powers(n + 1, 1);
    for(int i = 0; i < n; i++){
        hashh[i + 1] = (hashh[i] * power + (my_string[i] - 'a' + 1)) % mod;
        powers[i + 1] = (powers[i] * power) % mod;
    }

    return {hashh, powers};
}

long long get_hash(const vector<long long> &hashh, const vector<long long> &powers, int left, int right, long long mod){
    long long result = (hashh[right] - hashh[left] * powers[right - left]) % mod;
    if(result < 0){
        result += mod;
    }
    return result;
}

int k;

string get_common_substring(vector<string> &my_vector, int len){
    if(len == 0){
        return "";
    }

    auto p1 = prefix_hash(my_vector[1], mod1, power1);
    vector<long long> hashh1 = p1.first;
    vector<long long> powers1 = p1.second;
    auto p2 = prefix_hash(my_vector[1], mod2, power2);
    vector<long long> hashh2 = p2.first;
    vector<long long> powers2 = p2.second;

    unordered_set<uint64_t> common;

    for(int i = 0; i + len <= my_vector[1].size(); i++){
        long long x1 = get_hash(hashh1, powers1, i, i + len, mod1);
        long long x2 = get_hash(hashh2, powers2, i, i + len, mod2);
        uint64_t key = ((uint64_t)x1 << 32) ^ x2;
        common.insert(key);
    }

    for(int idx = 2; idx <= k; idx++){
        auto p1 = prefix_hash(my_vector[idx], mod1, power1);
        hashh1 = p1.first;
        powers1 = p1.second;
        auto p2 = prefix_hash(my_vector[idx], mod2, power2);
        hashh2 = p2.first;
        powers2 = p2.second;

        unordered_set<uint64_t> cur;
        int n = my_vector[idx].size();
        for(int i = 0; i + len <= n; i++){
            long long x1 = get_hash(hashh1, powers1, i, i + len, mod1);
            long long x2 = get_hash(hashh2, powers2, i, i + len, mod2);
            uint64_t key = ((uint64_t)x1 << 32) ^ x2;
            cur.insert(key);
        }
        
        unordered_set<uint64_t> next;
        for(auto &x : common){
            if(cur.count(x)){
                next.insert(x);
            }
        }
        
        common.swap(next);
        if(common.empty()){
            return "";
        }
    }

    p1 = prefix_hash(my_vector[1], mod1, power1);
    hashh1 = p1.first;
    powers1 = p1.second;
    p2 = prefix_hash(my_vector[1], mod2, power2);
    hashh2 = p2.first;
    powers2 = p2.second;
    int n = my_vector[1].size();

    for(int i = 0; i + len <= n; i++){
        long long x1 = get_hash(hashh1, powers1, i, i + len, mod1);
        long long x2 = get_hash(hashh2, powers2, i, i + len, mod2);
        uint64_t key = ((uint64_t)x1 << 32) ^ x2;
        
        if(common.count(key)){
            return my_vector[1].substr(i, len);
        }
    }

    return "";
}

int main(){

    int left = 0;
    int right = INT_MAX;

    cin >> k;
    vector<string> my_vector(k + 5);
    for(int i = 1; i <= k; i++){
        cin >> my_vector[i];
        right = min<int>(right, my_vector[i].size());
    }

    string ans = "";

    while(left <= right){
        int mid = left + (right - left) / 2;
        string temp = get_common_substring(my_vector, mid);
        if(!temp.empty()){
            ans = temp;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}