// Prime Numbers

#include <iostream>
#include <vector> 
using namespace std;

int main(){

    

    int input, cnt = 0, cnt_prime = 0, num = 2; 
    
    cin >> input; // 5

    while (cnt_prime != input){ // work until we get all the prime numbers

        for(int i = 2; i <= num; i++){ // if the 
            if(num % i == 0){
                cnt++;
            }
        }
        
        if(cnt == 1){
            cnt_prime++;
        }

        if(cnt_prime == input){
            cout << num;
            break;
        }

        num++;
        cnt = 0;
    }

    return 0;
}