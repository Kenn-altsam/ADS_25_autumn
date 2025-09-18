// Database

#include <iostream>
#include <climits>
using namespace std;

struct Node{ // declaring the struct
    string data;
    Node* next;
    Node* prev;

    Node(string new_data){ // Struct constructor
        data = new_data;
        next = nullptr;
        prev = nullptr;
    }
};

int main(){

    int n, cnt = 0;
    string x; 

    cin >> n;

    Node* head = nullptr; // setting head and tail pointers to nullptr
    Node* tail = nullptr; 

    for(int i = 0; i < n; i++){ // this loop is for creating the nodes and connecting them
        cin >> x;
        Node* node = new Node(x);

        if(head == nullptr){ // if the head pointer is nullptr, set head and tail to node
            head = tail = node; 
            cnt++;
        }
        else{
            if(x != tail->data){
                cnt++;
            }
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    cout << "All in all: " << cnt << endl;
    cout << "Students:" << endl;


    Node* cur = tail; // make the cur pointer that points to head

    while(cur != nullptr){
        cout << cur->data << endl; // Print current value

        // Skip all previous duplicates of the current value
        while(cur->prev != nullptr && cur->data == cur->prev->data){ // Skip backwards through all duplicates 
            cur = cur->prev; // of this value (find the start of this duplicate group)
        }
        cur = cur->prev; // Move to the previous unique value (the one before this duplicate group)
    }

    return 0;
}