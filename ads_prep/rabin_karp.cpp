#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;
const int prime = 31;

vector<long long> prefix_hash(string my_string){
    int n = my_string.size();
    vector<long long> hashh(n + 5, 0);
    vector<long long> powers(n + 5, 1);

    for(int i = 0; i < n; i++){
        hashh[i + 1] = (hashh[i] * prime + (my_string[i] - 'a' + 1)) % mod;
        powers[i + 1] = (powers[i] * prime) % mod;
    }
    return hashh;
}

long long get_hash(const string &my_string){
    long long hashh = 0, p = 1;
    for(int i = 0; i < my_string.size(); i++){
        hashh = (hashh * prime + (my_string[i] - 'a' + 1)) % mod;
    }
    return hashh;
}

int main(){

    string text = "ababcababc";
    string pattern = "abc";

    int n = text.size();
    int m = pattern.size();

    long long pattern_hash = get_hash(pattern);

    long long power = 1;
    for(int i = 0; i < m - 1; i++){
        power = (power * prime) % mod;
    }

    long long text_hash = get_hash(text.substr(0, m));

    for(int i = 0; i <= n - m; i++){
        if(pattern_hash == text_hash){
            if(text.substr(i, m) == pattern){
                cout << "Found at position: " << i << endl;
            }
        }

        if(i < n - m){
            text_hash = (text_hash - (text[i] - 'a' + 1) * power) % mod; // Remove the old leftmost character’s effect.
            if(text_hash < 0){
                text_hash += mod;
            }
            text_hash = (text_hash * prime + (text[i + m] - 'a' + 1)) % mod; // Shift all remaining characters one position left (multiply by prime).
        }                                                                    // Add the new character at the end.
    }

    return 0;
}