// Prime or not
// Print “YES” (without quotes) if the number is prime. Otherwise print “NO” (without quotes)

#include <iostream>
using namespace std;

int main(){

    int num, cnt = 0; 

    cin >> num;

    bool is_prime = true;

    if(num == 1){
        is_prime = false; // if the number is 1, return false
    }
    else{
        for(int i = 2; i * i <= num; i++){ // checking integers until the square root of the given number
            if(num % i == 0){ // if it divides - return false
                is_prime = false;
                break;
            }
        }
    }

    if (is_prime){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}