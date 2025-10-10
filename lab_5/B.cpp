// With each turn, we choose the two heaviest rocks and smash them together. 
// Suppose the stones have weights x and y with x <= y. If x==y, both stones are totally destroyed. 
// If x!=y, the stone of weight x is totally destroyed, and the stone of weight y has a new weight y - x.

#include <iostream>
#include <queue>
using namespace std;

int main(){

    priority_queue<long long> my_queue; // declaring a priority queue

    long long n, x, first, second; 
    cin >> n;

    for(int i = 0; i < n; i++){ // getting the numbers
        cin >> x;
        my_queue.push(x);
    }

    while(my_queue.size() > 1){ // work until the size of the queue greater than 1, because that would be our result 
        first = my_queue.top(); // get the heaviest element
        my_queue.pop();         // remove the heaviest element
        second = my_queue.top(); // get the second heaviest element
        my_queue.pop();          // remove the second heaviest element

        if(first != second){ // if two elements are the same subtract first from second 
            my_queue.push(first - second); // and add to the queue
        }                                  // if two elements are the same, we already remove them both, by pop()
    }

    if(my_queue.empty()){ // if the queue is empty at the end, print 0
        cout << 0;
    } 
    else{
        cout << my_queue.top(); // otherwise, print the one left element
    }

    return 0;
}