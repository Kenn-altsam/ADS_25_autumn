#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const long long mod = 1e9 + 7;
const int power = 31;

vector<long long> prefix_hash(string my_string){
    int n = my_string.size();
    vector<long long> hashh(n + 1, 0);
    vector<long long> powers(n + 1, 1);
    for(int i = 0; i < n; i++){
        hashh[i + 1] = (hashh[i] * power + (my_string[i] - 'a' + 1)) % mod;
        powers[i + 1] = (powers[i] * power) % mod;
    }
    return hashh;
}

long long get_hash(const vector<long long> &hashh, const vector<long long> &powers, int left, int right){
    long long result = (hashh[right] - hashh[left] * powers[right - left]) % mod;
    if(result < 0){
        result += mod;
    }
    return result;
}

string my_array[150];
string long_string;
long long string_cnt[155];

void solve(int n){
    long long mx = INT_MIN;
    for(int i = 0; i < n; i++){
        cin >> my_array[i];
    }

    cin >> long_string;

    vector<long long> hashh = prefix_hash(long_string);
    vector<long long> powers(long_string.size() + 1, 1);

    for(int i = 1; i <= long_string.size(); i++){
        powers[i] = (powers[i - 1] * power) % mod;
    }

    for(int i = 0; i < n; i++){
        long long hash_s = 0;
        long long cnt = 0;

        for(char c : my_array[i]){
            hash_s = (hash_s * power + (c - 'a' + 1)) % mod;
        }

        for(int j = 0; j + my_array[i].size() <= long_string.size(); j++){
            long long substr_hash = get_hash(hashh, powers, j, j + my_array[i].size());
            if(substr_hash == hash_s){
                cnt++;
            }
        }
        mx = max(mx, cnt);
        string_cnt[i] = cnt;
    }

    cout << mx << endl;
    for(int i = 0; i < n; i++){
        if(string_cnt[i] == mx){
            cout << my_array[i] << endl;
        }
    }
}

int main(){

    int times;

    while(true){
        cin >> times;

        if(times == 0){
            break;
        }
        else{
            solve(times);
        }
    }

    return 0;
}