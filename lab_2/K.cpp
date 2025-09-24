// One-time guests
// The task is to find the first (or leftmost) non-repeating character each time a character is inserted to the stream.

#include <iostream>
#include <map>
#include <climits>
using namespace std;

struct Node{ // declaring the struct
    char data;
    Node* next;

    Node(char new_data){ // Struct constructor
        data = new_data;
        next = nullptr;
    }
};

int main(){

    int times, n; // times is for each test case
    char my_char;

    cin >> times; 

    while(times--){ 

        map<char, int> my_map;

        cin >> n;

        Node* head = NULL; // setting head and tail pointers to nullptr
        Node* tail = NULL;

        for(int i = 0; i < n; i++){ // this loop is for creating the nodes and connecting them
            cin >> my_char;
            Node* node = new Node(my_char);

            if(head == NULL){ // if the head pointer is nullptr, set head and tail to node
                head = tail = node; 
            }
            else{
                tail->next = node; // if the head node already exists, 1. connect the tail to a new node
                tail = node; // 2. make the new node the tail
            }

            Node* cur = head; // make the cur pointer that points to head
            my_map[my_char]++; // count the number of times the char occurs

            while(cur != NULL && my_map[cur->data] > 1){ // while we don't reach the end of LL and the number's
                cur = cur->next;                            // frequency is higher than 1 
            }

            if(cur == NULL){
                cout << -1 << " ";
            }
            else{
                cout << cur->data << " ";
            }
        }
        cout << endl;
    }

    return 0;
}