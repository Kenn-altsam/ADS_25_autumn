#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;
const int prime = 31;

long long get_hash(const string &my_string){
    long long hashh = 0;
    for(int i = 0; i < my_string.size(); i++){
        hashh = (hashh * prime + (my_string[i] - 'a' + 1)) % mod;
    }

    return hashh;
}

int solve(const string &text, const string &pattern){
    long long pattern_hash = get_hash(pattern);

    int n = text.size();
    int m = pattern.size();

    long long power = 1;
    for(int i = 0; i < m - 1; i++){
        power = (power * prime) % mod;
    }

    int cnt = 0;

    long long text_hash = get_hash(text.substr(0, m));

    for(int i = 0; i <= n - m; i++){
        if(text_hash == pattern_hash){
            if(text.substr(i, m) == pattern){
                cnt++;
            }
        }

        if(i < n - m){
            text_hash = (text_hash - (text[i] - 'a' + 1) * power) % mod;
            if(text_hash < 0){
                text_hash += mod;
            }
            text_hash = (text_hash * prime + (text[i + m] - 'a' + 1)) % mod;
        }
    }
    
    return cnt;
}

int main(){

    string text = "banana";
    string pattern1 = "an";
    string pattern2 = "na";

    int first = solve(text, pattern1);
    int second = solve(text, pattern2);
    
    cout << first << endl << second;

    return 0;
}