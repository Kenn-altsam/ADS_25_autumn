#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> my_vector = {1, 2, 2, 2, 2, 3, 5, 6};

    vector<int>::iterator upper = upper_bound(my_vector.begin(), my_vector.end(), 2);
    vector<int>::iterator lower = lower_bound(my_vector.begin(), my_vector.end(), 2);

    cout << upper - lower;


    return 0;
}