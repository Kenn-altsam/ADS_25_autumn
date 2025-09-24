// Database
// It is known that duplicates of the same name occupy subsequent positions in the list. 
// Show how many students we have and print all these student’s name line by line. 
// By completing the template it is done automatically.

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
            if(x != tail->data){ // if the new element is not equal to the tail of the LL, add it to the LL
                cnt++;
                tail->next = node; 
                node->prev = tail;
                tail = node;
            }
        }
    }

    cout << "All in all: " << cnt << endl;
    cout << "Students:" << endl;


    Node* cur = tail; // make the cur pointer that points to head

    while(cur != nullptr){
        cout << cur->data << endl; // Print current value
        cur = cur->prev; // Move to the previous node
    }

    return 0;
}