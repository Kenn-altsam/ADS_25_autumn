// Vanya and Primes 2
// You need to find a prime whose index is n-th prime.
#include <iostream>
using namespace std;


// The function for finding the prime numbers
bool is_prime(int a){
    bool prime = true;
    if(a == 1){
        prime = false;
    }
    else{
        for(int i = 2; i * i <= a; i++){
            if(a % i == 0){
                prime = false;
                break;
            }
        }
    }

    if(prime){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    int input, cnt_superprime = 0, cnt_index = 0, num = 2;

    cin >> input;

    while(cnt_superprime != input){
    
        if(is_prime(num)){ // 2, 3, 5, 7 if our num is prime, then we add 1 to the counter of primes
            cnt_index++;   // 1, 2, 3, 4

            if(is_prime(cnt_index)){ // then we check if the indexes of the our nums are prime or not
                cnt_superprime++; // if the index of the prime number that we found is also prime - add 1
                                  // to the counter of superprimes
                
                if(cnt_superprime == input){ // if the initial value of the counter of superprimes
                    cout << num; // is equal to the input, print the current number that prime and break out of loop
                    break;
                }
            }
        }
    
        num++;
    }

    return 0;
}