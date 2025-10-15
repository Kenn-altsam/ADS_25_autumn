// To debug his project faster, Jonathan wants to define number of block in which he made a mistake
// 2 1
// 3 4
// 5
// In the first sample lines [1, 3] belong to the first block and lines [4, 7] to the second. So, Jonathan will
// find mistake at the fifth line at the second block.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n, m, x, sum = 0;

    cin >> n >> m;

    vector<int> ends;

    for(int i = 0; i < n; i++){ // find the sum of all elements to create the prefix-sums vector
        cin >> x;
        sum += x;
        ends.push_back(sum);
    }

    vector<int> mistakes;
    for(int i = 0; i < m; i++){
        cin >> x;
        vector<int>::iterator it = lower_bound(ends.begin(), ends.end(), x); // find the lower_bound of the mistake, lower_bound returns the index of the element that is greater or equal to the element
        int index = it - ends.begin(); // find the index
        mistakes.push_back(index); // push the index to the vector of mistakes
    }

    for(int i = 0; i < m; i++){
        cout << mistakes[i] + 1 << endl;
    }

    return 0;
}