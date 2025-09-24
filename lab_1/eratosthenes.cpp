#include <iostream>
#include <vector>
using namespace std;

vector<size_t> primes(size_t n){
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for(int i = 2; i * i <= n; i++){ // we need i * i <= n, because if we had < and n = 4; the for loop wouldn't have worked
        if(is_prime[i] == true){ // if the number that we have is true -> 
            for(int j = i * i; j <= n; j += i){ // -> mark all the next multiples of it starting from square of it -> 
                is_prime[j] = false;            // -> false
            }
        }
    }

    vector<size_t> result; 

    for(int i = 0; i < is_prime.size(); i++){ // checking all the elements in the is_prime vector, and if the 
        if(is_prime[i]){                      // ith element is true, add the i to the result vector
            result.push_back(i);
        }
    }

    return result;
    
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