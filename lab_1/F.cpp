// Prime Numbers
// Print n-th prime number.

#include <iostream>
#include <vector> 
using namespace std;

int main(){

    int input, cnt_prime = 0, num = 2; 
    
    cin >> input; // 5
    
    bool is_prime = true;

    while (cnt_prime < input){ // work until we get all the prime numbers
        is_prime = true;

        for(int i = 2; i * i <= num; i++){ // going until the sqrt of num
            if(num % i == 0){
                is_prime = false;
            }
        }

        if(is_prime){
            cnt_prime++;
        }

        if(cnt_prime == input){
            cout << num;
            break;
        }

        num++;
        
    }

    return 0;
}