// How many times Mark should mix his mixtures to get the densities of all mixtures >= m?

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

    priority_queue<long long, vector<long long>, greater<long long>> my_queue; // declaring a priority queue with min-heap

    long long n, m, x, first, second, cnt = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++){ // getting the numbers
        cin >> x;
        my_queue.push(x);
    }

    while(my_queue.top() < m && my_queue.size() > 1){ // we work until the size of the queue is greater than 1, because we need two mixtures to combine and we need to make all the densities greater or equal to m, so if the top of the queue greater than m, then all the others are greater too
        first = my_queue.top(); // get the least element
        my_queue.pop();         // remove the least element
        second = my_queue.top(); // get the second least element
        my_queue.pop();         // remove the second lightest element

        my_queue.push(first + 2 * second); // this formula is given
        cnt++; // count how many times we need to the mix
    }

    if(!my_queue.empty()){ // if the queue is not empty, check two things
        if(my_queue.top() >= m){ // if the top of the queue is greater or equal to m, print cnt
            cout << cnt;
        }
        else{ // if there's one element left in the queue, and it's not greater or equal to m, print -1
            cout << -1;
        }
    }
    else{ // if the queue is empty, print -1
        cout << -1;
    }

    return 0;
}