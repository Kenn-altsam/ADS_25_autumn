#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;
const int power = 31;

vector<long long> prefix_hash(string my_string){
    vector<long long> h(my_string.size() + 1, 0), p(my_string.size() + 1, 1);
    for(int i = 0; i < my_string.size(); i++){
        h[i + 1] = (h[i] * power + (my_string[i] - 'a' + 1)) % mod;
        p[i + 1] = (p[i] * power) % mod;
    }
    return h;
}

long long get_hash(const vector<long long> &h, const vector<long long> &p, int left, int right){
    long long result = (h[right] - h[left] * p[right - left]) % mod;
    if(result < 0){
        result += mod;
    } 
    return result;
}

int main(){
    
    string my_string1, my_string2, pattern;

    cin >> my_string1 >> my_string2 >> pattern;

    int n = my_string1.size();
    int m = pattern.size();

    vector<long long> h1 = prefix_hash(my_string1);
    vector<long long> h2 = prefix_hash(my_string2);

    vector<long long> p(n + 1, 1);
    for(int i = 1; i <= n; i++){
        p[i] = (p[i - 1] * power) % mod;
    }

    long long hash_t = 0;
    for(int i = 0; i < pattern.size(); i++){
        hash_t = (hash_t * power + (pattern[i] - 'a' + 1)) % mod;
    }

    int cnt = 0;
    for(int i = 0; i + m <= n; i++){
        long long hs1 = get_hash(h1, p, i, i + m);
        long long hs2 = get_hash(h2, p, i, i + m);
        if(hs1 == hash_t && hs2 == hash_t){
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}