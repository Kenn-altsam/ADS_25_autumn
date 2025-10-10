// [6, 5, 3, 9] –> First, merge arrays of lengths 5 and 3 that will cost 8.
// [6, 8, 9] –> Next, merge arrys of lengths 6 and 8 that will cost 14.
// [14, 9] –> Finally, merge the remaining two arrays that will cost 23.
// Therefore, the total cost for merging all arrays is 8 + 14 + 23 = 45.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

    priority_queue<long long, vector<long long>, greater<long long>> my_queue; // declaring a priority queue with min-heap

    long long n;
    long long x, first, second;
    long long sum = 0;
    cin >> n;

    for(int i = 0; i < n; i++){ // getting the numbers
        cin >> x;
        my_queue.push(x);
    }

    while(my_queue.size() > 1){ // work until we have 1 element left in the queue, because we can't add the number with itself
        first = my_queue.top(); // get the lightest element
        my_queue.pop();         // remove the lightest element
        second = my_queue.top(); // get the second lighest element
        my_queue.pop();         // remove the second lightest element

        sum += first + second; // get the sum of first and second lightest elements
        my_queue.push(first + second); // add it back to the priority queue
    }

    cout << sum; // print the sum 

    return 0;
}