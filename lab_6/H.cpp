#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;

    char my_char;

    int my_array[26] = {0};

    for(int i = 0; i < n; i++){
        cin >> my_char;
        my_array[my_char - 'a'] = 1;
    }

    cin >> my_char;

    for(int i = my_char - 'a' + 1; i < 26; i++){
        if(my_array[i]){
            cout << char(i + 'a');
            return 0;
        }
    }

    for(int i = 0; i < my_char - 'a'; i++){
        if(my_array[i]){
            cout << char(i + 'a');
            return 0;
        }
    }

    return 0;
}