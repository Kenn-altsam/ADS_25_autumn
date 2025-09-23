// Royal Flush
//We pick up 1 card and put it on the back of the deck.
// Now, we pick up another card, it turns out to be card numbered 1, we put it outside the deck.

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

bool check_valid(deque<int> dq, int n) {

    for(int i = 1; i <= n; i++){
        int k = i;

        while(k-- && !dq.empty()){ // Check exactly like in the given of the assignment 
            int temp = dq.front(); // get temp value
            dq.pop_front(); // remove the front element 
            dq.push_back(temp); // put it at the back 
        }

        if (dq.empty() || dq.front() != i){ // if after those arrengements the dq is empty or the
            return false;                   // front element is not the same as the expected i'th element return false
        }
        dq.pop_front(); // if the element is the expected one -> remove the front element 
    }

    return true; 
}

int main(){

    deque<int> dq;

    int times;

    cin >> times;

    vector<string> my_vector;
    string res;

    while(times--){ // work until the amount of times we need to get the results equals to zero 
        int n;
        cin >> n;

        for(int i = n; i >= 1; i--){ // check in reverse 
            dq.push_front(i); // we add to the front 

            for(int j = 0; j < i; j++){ // then swap the elements i amount of times
                int temp_num = dq.back();
                dq.pop_back();
                dq.push_front(temp_num);
            }
        }

        res = "";

        if (!check_valid(dq, n)){ // check if the dq is valid after swappings and if not return -1
            return -1;
        }
        else{
        for(int elem : dq){
                res += (to_string(elem) + " "); // if it's valid, add the dq elements to the 'res' string
            }
        my_vector.push_back(res);

        dq.clear(); // empty the dq to work with the next input 

        }
    }

    for(int i = 0; i < my_vector.size(); i++){ // show all the strings at the end 
        cout << my_vector[i] << "\n";
    }

    return 0;
}
