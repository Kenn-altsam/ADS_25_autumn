// Ragnarok
// Find non-empty subarray of a (range of consequent elements) of maximal sum.

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

int findMaxSum(int n, Node* head){ // function for finding max consequtive sum

    int mx = INT_MIN, sum;
    Node* cur = head; 
    for(int i = 0; i < n; i++){ // working with every node in our pointer
        sum = 0;
        cur = head;
        head = head->next; // making the next nodes as the head nodes
        while(cur != nullptr){ // adding the nodes' data starting from each node until the end node 
            sum += cur->data;
            if(sum > mx){ // if the sum is greater than the max, make max the sum 
                mx = sum;
            }
            cur = cur->next;
        }
    }
    return mx;
}

int main(){

    int n, x;

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

    cout << findMaxSum(n, head);

    return 0;
}