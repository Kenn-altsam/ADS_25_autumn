#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

    priority_queue<long long, vector<long long>, greater<long long>> my_queue; // declaring a priority queue with min-heap,
                                                                               //  because we need to sort out the boxes
                                                                               // with min candies when we reach the number k boxes,
                                                                               // the max ones will stay at the end and we won't compare them,
                                                                               // the newly-come element would find its position
                                                                               // after comparing with the min, because priority_queue
                                                                               // sorts every time the new element is added
    vector<long long> my_vector; // this is for storing results

    long long n, k, x, first, sum = 0;
    cin >> n >> k;

    string my_string;

    for(long long i = 0; i < n; i++){ // getting the queries, either print or insert 
        cin >> my_string;
        if(my_string == "print"){ // if it's print, just add the sum to my_vector
            my_vector.push_back(sum);
        }
        else if(my_string == "insert"){ // if it's insert, get the x and
            cin >> x;
            if(my_queue.size() == k){ // if we reach the k elements in the queue
                first = my_queue.top(); // get the box with the least elements
                sum -= my_queue.top(); // and subtract the number of candies in it from the sum 
                my_queue.pop(); // remove this box from the queue
                my_queue.push(max(first, x)); // compare this box with new one, 
                                              // if this deleted box is greater than the new one, 
                                              // add it back to the queue, otherwise add the new one to the queue
                sum += max(first, x); // add the number of candies from max of the box with least candies and the new box, to the sum
            }
            else{
                my_queue.push(x); // if we don't reach the k, just add the element to the queue
                sum += x;
            }   
        }
    }

    for(long long i = 0; i < my_vector.size(); i++){ // print the elements of the my_vector
        cout << my_vector[i] << endl;
    }

    return 0;
}