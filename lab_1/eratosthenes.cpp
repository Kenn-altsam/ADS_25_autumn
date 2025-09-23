#include <iostream>
#include <vector>
using namespace std;

vector<size_t> primes(int n){
    vector<bool> is_prime(n + 1, false);

    
}

int main(){

    int n;

    vector<size_t> my_vector;

    cin >> n;

    my_vector = primes(n);

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << ' ';
    }

    return 0;
}