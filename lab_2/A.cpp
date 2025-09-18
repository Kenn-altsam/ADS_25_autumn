// Nearest number

#include <iostream>
#include <climits>
using namespace std;

struct Node{ // declaring the struct
    int data;
    Node* next;

    Node(int new_data){ // Struct constructor
        data = new_data;
        next = nullptr;
    }
};

int main(){

    int n, x, k, needed_pos, cnt = 0, mn = INT_MAX; 

    cin >> n;

    Node* head = nullptr; // setting head and tail pointers to nullptr
    Node* tail = nullptr; 

    for(int i = 0; i < n; i++){ // this loop is for creating the nodes and connecting them
        cin >> x;
        Node* node = new Node(x);

        if(head == nullptr){ // if the head pointer is nullptr, set head and tail to node
            head = tail = node; 
        }
        else{
            tail->next = node; // if the head node already exists, 1. connect the tail to a new node
            tail = node; // 2. make the new node the tail
        }
    }

    Node* cur = head; // make the cur pointer that points to head

    cin >> k;

    while(cur != nullptr){ // work until we reach the ending node that has a pointer equal to nullptr
        if(abs(cur->data - k) < mn){ // if the abs value of the node's data - given number k is less than min
            mn = abs(cur->data - k); // set the min this result
            needed_pos = cnt; // save the needed position of the minimum value
        }
        cur = cur->next; // move to the next node
        cnt++; // increase the cnt
    }

    cout << needed_pos; // print the position of the minimum value, and this is the offset result we need

    return 0;
}