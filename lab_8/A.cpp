#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const long long mod = 1e9 + 7;
vector<string> my_vector;
unordered_set<string> my_set;
 
string get_hash(const string &my_string){ // get the hash of the whole string 
    long long h = 0, p = 1; // h is like a 
    for(int i = 0; i < my_string.size(); i++){
        h = (h + ((my_string[i] - 47) * p) % mod) % mod;
        p = (p * 11) % mod;
    }

    return to_string(h);
}  

void solve(){
    int n; 
    string my_string;

    cin >> n;

    for(int i = 0; i < 2 * n; i++){
        cin >> my_string;
        my_vector.push_back(my_string);
        my_set.insert(my_string);
    }

    int cnt = 0;

    for(int i = 0; i < my_vector.size(); i++){
        if(cnt == n){
            break;
        }
        string hash_string = get_hash(my_vector[i]);
        if(my_set.find(hash_string) != my_set.end()){
            cout << "Hash of string \"" << my_vector[i] << "\"" << " is " << hash_string << endl;
            cnt++;
        }
    }
}

int main(){

    solve();

    return 0;
}