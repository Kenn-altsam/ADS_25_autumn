#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check_vowel(char my_char){
    if(my_char == 'a' || my_char == 'e' || my_char == 'i' || my_char == 'o' || my_char == 'u'){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    int n;
    string my_string;

    cin >> n >> my_string;

    vector<char> vowels;
    vector<char> consonants;

    for(int i = 0; i < n; i++){
        if(check_vowel(my_string[i])){
            vowels.push_back(my_string[i]);
        }
        else{
            consonants.push_back(my_string[i]);
        }
    }

    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());

    for(int i = 0; i < vowels.size(); i++){
        cout << vowels[i];
    }

    for(int i = 0; i < consonants.size(); i++){
        cout << consonants[i];
    }

    return 0;
}