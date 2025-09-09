#include <iostream>
#include <vector> 
#include <climits>
using namespace std;

int main(){

    int number_of_people;
    int number;
    vector<int> numbers; 

    cin >> number_of_people;

    for (int i = 0; i < number_of_people; i++){
        cin >> number;
        numbers.push_back(number);
    }

    cout << -1 << " ";

    bool less_exists = false;

    for (int i = 1; i < number_of_people; i++){
        int j = i - 1;

        less_exists = false;

        while(j >= 0){
            if (numbers[i] >= numbers[j]){
                cout << numbers[j] << " ";
                less_exists = true;
                break;
            }
            else{
                j--;
            }
        }

        if (less_exists == false){
            cout << -1 << " ";
        }
    }

    return 0;
}