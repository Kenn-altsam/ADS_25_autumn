#include <iostream>
#include <vector>
using namespace std;

void eratosthenes(int n){   
    vector<int> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= n; i++){
        if(is_prime[i] == true){
            for(int j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }

    for(int i = 0; i <= n; i++){
        if(is_prime[i] == true){
            cout << i << ' ';
        }
    }
}

int main(){

    int n;
    
    cin >> n;

    eratosthenes(n);

    return 0;
}