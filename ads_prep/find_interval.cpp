#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> my_vector = {1, 3, 5, 6, 7, 9};

    vector<int>::iterator upper = upper_bound(my_vector.begin(), my_vector.end(), 7);
    if(upper != my_vector.end()){
        cout << *upper << endl;
    }
    vector<int>::iterator lower = lower_bound(my_vector.begin(), my_vector.end(), 3);

    cout << upper - lower;
    
    return 0;
}