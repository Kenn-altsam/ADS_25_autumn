#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;
const long long power = 31;

int main(){

    long long n;
    long long hashh[51];
    long long powers[51];
    long long my_array[51];

    cin >> n;

    powers[0] = 1;

    for(int i = 1; i < 51; i++){
        powers[i] = powers[i - 1] * 2;
    }

    for(int i = 0; i < n; i++){
        cin >> my_array[i];
        long long cur;
        if(i > 0){
            cur = (my_array[i] - my_array[i - 1]) / powers[i] + 97;
        }
        else{
            cur = my_array[i] + 97;
        }
        cout << char(cur);
        //h[i] = h[i-1] + 2^i * (s[i] - 97);
        //h[i] = h[i-1] + s[i] * 2^i - 97 * 2^i
        //(h[i] - h[i-1])/2^i + 97 = s[i]
        //7 = 0 + s[i] * 2^0 - 97 * 2^0
    }

    return 0;
}