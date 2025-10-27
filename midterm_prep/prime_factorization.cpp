// Eratosthenes

#include <iostream>
using namespace std;

void eratosthenes(int n){

    int cnt = 0;

    vector<bool> my_vector(n + 1, true);
    my_vector[0] = my_vector[1] = false;

    for(int i = 2; i * i <= n; i++){
        if(my_vector[i] == true){
            for(int j = i * i; j <= n; j += i){
                my_vector[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(my_vector[i] == true){
            cout << i << ' ';
            cnt++;
        }
    }
    cout << endl << cnt;
}


int main(){

    int n; 
    cin >> n;

    eratosthenes(n);

    return 0;
}