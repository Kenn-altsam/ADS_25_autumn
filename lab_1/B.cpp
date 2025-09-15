// Nugman and Stack

#include <iostream>
#include <vector> 
#include <climits>
using namespace std;

int main(){

    int number_of_people;
    int number;
    vector<int> numbers; 

    cin >> number_of_people;

    for (int i = 0; i < number_of_people; i++){ // work for the whole size of elements
        cin >> number;
        numbers.push_back(number);
    }

    cout << -1 << " "; // the first is always -1 because it doesn't have the less element in front of it

    bool less_exists; // assign the checker that checks if less exists in front of the element

    for (int i = 1; i < number_of_people; i++){ // starting from the second element 
        int j = i - 1;  // j is for the element with index -1 than the current 

        less_exists = false;

        while(j >= 0){ // starting from the j until 0
            if (numbers[i] >= numbers[j]){  // if the element at the back is less than current make the checker -> true and break 
                cout << numbers[j] << " ";
                less_exists = true;
                break;
            }
            else{
                j--;
            }
        }

        if (less_exists == false){ // if after all the checks the less_exists is still false -> return -1 
            cout << -1 << " ";
        }
    }

    return 0;
}