#include <iostream>
using namespace std;

int main(){

    int num, cnt = 0; 

    cin >> num;

    if(num == 1){
        cout << "NO";
    }
    else{
        for(int i = 2; i <= num; i++){
            if(num % i == 0){
                cnt++;
            }
        }

        if(cnt > 1){
        cout << "NO";
        }
        else{
            cout << "YES";
        }
    }

    return 0;
}