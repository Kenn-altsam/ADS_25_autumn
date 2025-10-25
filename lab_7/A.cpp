#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

bool comparison(string a, string b){
    return a.size() < b.size();
}

int main(){

    int n;
    cin >> n;
    cin.ignore();

    while(n--){
        string my_string;
        getline(cin, my_string);

        stringstream ss(my_string);
        string word;
        vector<string> words;

        while(ss >> word){
            words.push_back(word);
        }

        stable_sort(words.begin(), words.end(), comparison);

        for(int i = 0; i < words.size(); i++){
            cout << words[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}