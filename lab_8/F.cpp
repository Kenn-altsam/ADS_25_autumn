#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <cstdint>
using namespace std;

const long long mod1 = 1e9 + 7;
const int power1 = 31;
const long long mod2 = 1e9 + 9;
const int power2 = 37;

vector<long long> hashh1(2002, 0), hashh2(2002, 0);
vector<long long> powers1(2002, 1), powers2(2002, 1);

pair<long long, long long> get_hash(int left, int right){ // get hash of the interval 
    pair<long long, long long> res = {(hashh1[right] - hashh1[left] * powers1[right - left]) % mod1, (hashh2[right] - hashh2[left] * powers2[right - left]) % mod2};
    if(res.first < 0){
        res.first += mod1;
    }
    if(res.second < 0){
        res.second += mod2;
    }
    return res;
}

int main(){

    for(int i = 1; i < 2002; i++){ // prefix powers
        powers1[i] = (powers1[i - 1] * power1) % mod1;
        powers2[i] = (powers2[i - 1] * power2) % mod2;
    }

    string my_string;
    unordered_set<uint64_t> my_set;

    cin >> my_string;

    int n = my_string.size();

    for(int i = 0; i < n; i++){ // get the hash vector
        hashh1[i + 1] = (hashh1[i] * power1 + (my_string[i] - 'a' + 1)) % mod1;
        hashh2[i + 1] = (hashh2[i] * power2 + (my_string[i] - 'a' + 1)) % mod2;
    }

    for(int i = 1; i <= my_string.size(); i++){
        for(int j = 0; j + i <= my_string.size(); j++){
            pair<long long, long long> pair = get_hash(j, i + j);
            uint64_t combine = ((uint64_t)pair.first << 32) | ((uint64_t)pair.second);
            my_set.insert(combine);
        }
    }

    cout << my_set.size();

    return 0;
}