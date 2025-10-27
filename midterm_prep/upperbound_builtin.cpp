#include <iostream>
#include <vector>
#include <algorithm>   
using namespace std;

int main(){

    vector<int> my_vector = {1, 29, 29, 29, 30, 60, 70};

    vector<int>::iterator upper_ = upper_bound(my_vector.begin(), my_vector.end(), 29);
    vector<int>::iterator lower_ = lower_bound(my_vector.begin(), my_vector.end(), 29);

    cout << upper_ - lower_;

    return 0;
}