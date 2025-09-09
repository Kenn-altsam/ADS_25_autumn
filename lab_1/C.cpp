#include <iostream>
#include <algorithm> 
using namespace std;

int main(){

    string first_string;
    string second_string;

    cin >> first_string;
    cin >> second_string;

    int count_slash_first = count(first_string.begin(), first_string.end(), '#'); // counting the amount of # in the first string
    int count_slash_second = count(second_string.begin(), second_string.end(), '#'); // counting the amount of # in the second string

    while(count_slash_first != 0){
        size_t pos = first_string.find('#');

        if (pos != string::npos && pos > 0){ // checking if the first string has #, and removing the elements before
            first_string.erase(pos - 1, 2);  // that slash and the # itself 
            count_slash_first--;
        }
    }

    while(count_slash_second != 0){
        size_t pos = second_string.find('#');
        
        if (pos != string::npos && pos > 0){ // same as with first string 
            second_string.erase(pos - 1, 2); 
            count_slash_second--;
        }
    }

    if (first_string == second_string){ // if two strings are the same, then print "YES"
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}