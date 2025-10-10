#include <iostream>
#include <map>
using namespace std;

int main(){

    int n = 6;

    int my_arr[] = {1, 1, 2, 3, 2, 9};
    int count_arr[10] = {0};

    for(int i = 0; i < 6; i++){
        count_arr[i]++;
    }

    int element = -1;

    for(int i = 0; i < 10; i++){
        if(count_arr[i] == 1){
            element = 1;
        }
    }

    for(int i = 0; i < n; i++){
        if(my_arr[i] == element){
            cout << i;
        }
    }

    return 0;
}