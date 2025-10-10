// The price of the ticket depends on the row. If there are k (k > 0) free seats in the row, 
// then the price of one ticket will be equal to k. 
// What is the maximum amount of money stadium management can get if there are x people in line for a ticket?

#include <iostream>
#include <queue>
using namespace std;

int main(){

    priority_queue<long long> my_queue; // getting the numbers

    long long n, k, x, first, cnt = 0, sum = 0;
    cin >> n >> k;

    for(int i = 0; i < n; i++){ // getting the numbers
        cin >> x;
        my_queue.push(x);
    }

    while(cnt < k){ // work until our cnt is less than k, meaning that until we sell k amount of tickets
        first = my_queue.top(); // get the first element
        my_queue.pop();         // remove the first element

        cnt++; // increase the count, meaning that we sold one ticket
        sum += first; // add the cost of that ticket, which has a price equal to the amount of seats left in that row
        my_queue.push(first - 1); // add the first - 1 to the queue, meaning that we sold one ticket
    }

    cout << sum; // print the sum

    return 0;
}