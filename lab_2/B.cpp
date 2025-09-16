#include <iostream>
using namespace std;

struct Node{ // declaring the struct
    string data;
    Node* next;

    Node(string new_data){ // Struct constructor
        data = new_data;
        next = nullptr;
    }
};

int main(){

    int n, k, cnt = 0;
    string x;

    cin >> n >> k;

    Node* head = nullptr; // setting head and tail pointers to nullptr
    Node* tail = nullptr;

    for(int i = 0; i < n; i++){ // this loop is for creating the nodes and connecting them
        cin >> x;
        Node* node = new Node(x);

        if(head == nullptr){ // if the head pointer is nullptr, set head and tail to node
            head = tail = node; // which means that the first head and tail first point to the same node 
        }
        else{
            tail->next = node; // if the head node already exists, 1. connect the tail to a new node
            tail = node; // 2. make the new node the tail
        }
    }

    Node* cur = head; // make the cur pointer that points to head

    while(cur != nullptr){ // work until we reach the ending node that has a pointer equal to nullptr
        if(cnt >= k){ // first we need to output the elements that have the cnt >= 2, meaning that we print the
            cout << cur->data << " "; // elements greater or equal to our given number k
        }
        cnt++; // increase the cnt after each loop of while loop
        cur = cur->next;
    }

    cnt = 0; // set the cnt to 0
    cur = head; // and move cur to head

    while(cnt < k){ // now we have to print elements before the index k that we have
        cout << cur->data << " "; // print the data of the node
        cur = cur->next; // move to the next node
        cnt++; // increase the cnt
    }

    return 0;
}