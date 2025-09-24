// Kuanyshbek
// delete each second element

#include <iostream>
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

    int n, x, cnt = 0;

    cin >> n;

    Node* head = nullptr; // setting head and tail pointers to nullptr
    Node* tail = nullptr;

    for(int i = 0; i < n; i++){ // this loop is for creating the nodes and connecting them
        cin >> x;
        Node* node = new Node(x); // create a new node
        
        if(head == nullptr){ // if the head pointer is nullptr, set head and tail to node
            head = tail = node;
        }
        else{
            tail->next = node; // if the head node already exists, 1. connect the current tail to a new node
            tail = node; // 2. make the new node the tail
        }
    }

    Node* cur = head; // make the cur pointer that points to head

    while(cur != nullptr){ // work until we reach the ending node that has a pointer equal to nullptr
        cnt++;
        if(cnt % 2 == 1){
            cout << cur->data << " ";
        }

        cur = cur->next;
    }

    return 0;
}