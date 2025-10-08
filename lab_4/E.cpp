// This task is for BFS using queue and array(or vector)
// Find the maximum width of the binary tree(but we don't have to create a binary tree)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){

    int n;
    int x, y, z;

    cin >> n;

    vector<int> left_children(n + 1, 0); // the vector for saving all the left children of all nodes
    vector<int> right_children(n + 1, 0); // the vector for saving all the right children of all nodes
    queue<int> my_queue; // queue is for implementing the BFS

    for(int i = 0; i < n - 1; i++){
        cin >> x >> y >> z;
        if(z == 0){ // if the z == 0, save to the left_children
            left_children[x] = y; // y is the child and x is parent which is represented by index 
        }
        else{ // if the z == 1, save to the right_children 
            right_children[x] = y;
        }
    }

    my_queue.push(1); // add the element 1 to the queue, which means it's the first and the root element
    int max_width = 0;

    while(!my_queue.empty()){ // work until the queue is empty 
        int cur_level = my_queue.size(); // the width of a level is the size of the queue
        max_width = max(max_width, cur_level); // if the current level's width is greater than max, update the max

        for(int i = 0; i < cur_level; i++){ // this for loop is for adding the children of every node in a queue 
            int temp = my_queue.front();    // and removing the parent node itself from the queue. 
            my_queue.pop(); // save the front element of the queue to the temp variable and remove it 

            if(left_children[temp] != 0){ // if there's an element with the parent's index in the left_children's vector, add this child to the queue
                my_queue.push(left_children[temp]); 
            }
            if(right_children[temp] != 0){ // if there's an element with the parent's index in the right_children's vector, add this child to the queue
                my_queue.push(right_children[temp]);
            }
        } 
    }

    cout << max_width; // print the max_width

    return 0;
}