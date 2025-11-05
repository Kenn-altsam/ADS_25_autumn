#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;
const int power = 31;

vector<long long> prefix_hash(string my_string){
    int n = my_string.size();
    vector<long long> hashh(n + 5, 0);
    vector<long long> powers(n + 5, 1);

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

int main(){

    string my_string, x, check;
    int n;
    cin >> my_string;

    for(int i = 0; i < my_string.size(); i++){
        check += '0';
    }

    vector<long long> hashh = prefix_hash(my_string);
    vector<long long> powers(my_string.size() + 1, 1);
    for(int i = 1; i <= my_string.size(); i++){
        powers[i] = (powers[i - 1] * power) % mod;
    }

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        long long hash_x = 0;

        for(int i = 0; i < x.size(); i++){
            hash_x = (hash_x * power + (x[i] - 'a' + 1)) % mod;
        }

        for(int j = 0; j + x.size() <= my_string.size(); j++){
            long long substr_hash = get_hash(hashh, powers, j, j + x.size());
            if(substr_hash == hash_x){
                for(int k = j; k < j + x.size(); k++){
                    check[k] = '1';
                }
            }
        }
    }

    for(int i = 0; i < check.size(); i++){
        if(check[i] == '0'){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}