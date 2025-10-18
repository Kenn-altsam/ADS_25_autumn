#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    string my_string;

    cin >> my_string;

    vector<int> my_vector;

    for(int i = 0; i < my_string.size(); i++){
        my_vector.push_back(my_string[i]);
    }

    sort(my_vector.begin(), my_vector.end());

    for(int i = 0; i < my_vector.size(); i++){
        cout << (char)my_vector[i];
    }

    return 0;
}