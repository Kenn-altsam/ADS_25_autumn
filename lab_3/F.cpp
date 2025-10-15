// Help Mark to count the number of competitors that he can win in each round and the total sum of their powers.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n, x, rounds, marks_power, sum;

    cin >> n; // getting the number competitors

    vector<int> powers; 

    for(int i = 0; i < n; i++){ // getting the powers of competitors
        cin >> x;
        powers.push_back(x);
    }

    cin >> rounds; // getting the number of rounds

    sort(powers.begin(), powers.end()); // 1 2 2 4 4 4 7 8 9 // sorting the vector
                              // 0 1 2 3 4 5 6

    vector<int> marks_powers;

    for(int i = 0; i < rounds; i++){ // getting marks' powers
        cin >> marks_power;
        marks_powers.push_back(marks_power);
    }

    for(int i = 0; i < rounds; i++){ // working for every round
        vector<int>::iterator it = upper_bound(powers.begin(), powers.end(), marks_powers[i]); // finding the upper bound
        int index = it - powers.begin(); // it's the first number greater than our target
        sum = 0;

        for(int j = 0; j < index; j++){ // sum all the numbers before the target
            sum += powers[j];
        }

        cout << index << ' ' << sum << endl; // print the index of target and the sum of all the numbers before it
    }

    return 0;
}

