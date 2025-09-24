// Insertion of Node
// Just insert the node

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

    int n, x, cnt = 0, inserted_data, pos;

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
            tail->next = node; // setting connection between current last node and the new node(connecting new wagon to the train)
            tail = node; // making the newly added node - the last node (saying that this added new wagon is a tail wagon)
        }
    }

    cin >> inserted_data >> pos;

    Node* new_node = new Node(inserted_data); // creating a the new node that needs to be inserted

    Node* cur = head; // make the cur pointer that points to head

    if(pos == 0){ // if the pos of the element that needs to be inserted is 0, then 
        new_node->next = head; // connect new_node to the current head node
        head = new_node; // make new_node the head node 1 -> 2 -> 3 -> 4 -> null 
    }
    else{
        while(cur != nullptr){ // if the pos is greater than 0, then 
            cnt++; // count the position by cnt
            if(cnt == pos){ // if the pos is equal to cnt, then
                new_node->next = cur->next; // connect new_node to the next element of the current cur node
                cur->next = new_node; // connect the current element to the new_node
                break;
            }
            cur = cur->next; // move to the next element in the linked list 
        }
    }

    cur = head; // set the cur to head again 

    while(cur != nullptr){ // print every cur until we reach till the end of the list 
            cout << cur->data << ' ';
            cur = cur->next;
    }

    return 0;
}