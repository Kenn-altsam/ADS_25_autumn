#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;
const int prime = 31;

vector<long long> prefix_hash(string my_string){
    int n = my_string.size();
    vector<long long> hashh(n + 5, 0);
    vector<long long> powers(n + 5, 0);

    for(int i = 0; i < n; i++){
        hashh[i + 1] = (hashh[i] * prime + (my_string[i] - 'a' + 1)) 
    }
}

int main(){



    return 0;
}