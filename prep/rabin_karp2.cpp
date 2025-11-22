// #include <iostream>
// using namespace std;

// const long long mod = 1e9 + 7;
// const int prime = 31;

// // vector<long long> prefix_hash(string my_string){
// //     int n = my_string.size();
// //     vector<long long> hashh(n + 5, 0);
// //     vector<long long> powers(n + 5, 1);

// //     for(int i = 0; i < n; i++){
// //         hashh[i + 1] = (hashh[i] * prime + (my_string[i] - 'a' + 1)) % mod;
// //         powers[i + 1] = (powers[i] * prime) % mod;
// //     }
// //     return hashh;
// // }

// vector<long long> prefix_hash(string my_string){
//     int n = my_string.size();
//     vector<long long> hashh(n + 5, 0);
//     vector<long long> powers(n + 5, 1);

//     for(int i = 0; i < n; i++){
//         hashh[i + 1] = (hashh[i] * prime + (my_string[i] - 'a' + 1)) % mod;
//         powers[i + 1] = (powers[i] * prime) % mod; 
//     }
//     return hashh;   
// }

// long long get_hash(const string &my_string){
//     long long hashh = 0, p = 1;
//     for(int i = 0; i < my_string.size(); i++){
//         hashh = (hashh * prime + (my_string[i] - 'a' + 1)) % mod;
//     }
//     return hashh;
// }

// int main(){

//     string text = "ababcababc";
//     string pattern = "abc";

//     int n = text.size();
//     int m = pattern.size();

//     long long pattern_hash = get_hash(pattern);

//     long long power = 1;
//     for(int i = 0; i < m - 1; i++){
//         power = (power * prime) % mod;
//     }

//     long long text_hash = get_hash(text.substr(0, m));

//     for(int i = 0; i <= n - m; i++){
//         if(pattern_hash == text_hash){
//             if(text.substr(i, m) == pattern){
//                 cout << "Found at position: " << i << endl;
//             }
//         }

//         if(i < n - m){
//             text_hash = (text_hash - (text[i] - 'a' + 1) * power) % mod; // Remove the old leftmost character’s effect.
//             if(text_hash < 0){
//                 text_hash += mod;
//             }
//             text_hash = (text_hash * prime + (text[i + m] - 'a' + 1)) % mod; // Shift all remaining characters one position left (multiply by prime).
//         }                                                                    // Add the new character at the end.
//     }

//     return 0;
// }

private:
    const int mod = 1e9 + 7;
    const int base = 31;
    vector<int> hashh;
    vector<int> powers;

    // modular addition
    // int add(int a, int b) {
    //     a += b;
    //     if (a >= mod) a -= mod;
    //     return a;
    // }

    // modular subtraction
    // int sub(int a, int b) {
    //     a -= b;
    //     if (a < 0) a += mod;
    //     return a;
    // }

    int sub(int a, int b){
        a -= b;
        if(a < 0){
            a += mod;
        }
        return a;
    }

    // modular multiplication
    // int mul(int a, int b) {
    //     return (int)((1LL * a * b) % mod);
    // }

    // int mult(int a, int b){
    //     return (int)((1LL * a * b) % mod);
    // }

    int add(int a, int b){
        a += b;
        if(a >= mod){
            a -= mod;
        }
        return a;
    }

    int mult(int a, int b){
        return (int)((1LL * a * b) % mod);
    }

    // convert character to int 
    // ('a' = 1, ..., 'z' = 26)
    int charToInt(char c) {
        return c - 'a' + 1;
    }



public:
    // constructor: precomputes prefix hashes and powers
    // RabinKarpHash(string &s) {
    //     int n = s.size();
    //     hash.resize(n);
    //     power.resize(n);

    //     hash[0] = charToInt(s[0]);
    //     power[0] = 1;

    //     for (int i = 1; i < n; ++i) {
    //         hash[i] = add(mul(hash[i - 1], base), charToInt(s[i]));
    //         power[i] = mul(power[i - 1], base);
    //     }
    // }

    // rabinkarp(string &my_string){
    //     int n = my_string.size();
    //     hash.resize(n);
    //     powers.resize(n);

    //     hashh[0] = my_string[0] - 'a' + 1;
    //     powers[0] = 1;

    //     for(int i = 1; i < n; i++){
    //         hashh[i] = 
    //     }
    // }

    rabinKarp(string &my_string){
        int n = my_string.size();
        hashh.resize(n);
        powers.resize(n);

        hashh[0] = my_string[0] - 'a' + 1;
        powers[0] = 1;

        for(int i = 1; i < n; i++){
            hashh[i] = (hashh[i - 1] * power + (my_string[i] - 'a' + 1)) % mod;
            powers[i] = (powers[i - 1] * power) % mod;
        }
    }

    int get_hash(int left, int right){
        int h = hashh[0];
        if(left > 0){
            h = (h - h[left - 1] * powers[right - left + 1]);
        }
        return h;
    }

    // get hash of substring s[l...r] in O(1)
    int getSubHash(int l, int r) {
        int h = hash[r];
        if (l > 0) {
            h = sub(h, mul(hash[l - 1], power[r - l + 1]));
        }
        return h;
    }
};