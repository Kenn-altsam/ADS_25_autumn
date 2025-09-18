// One-time guests

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

    int times, n;
    char my_char;

    cin >> times;

    

    while(times--){

        map<char, int> my_map;

        cin >> n;

        Node* head = nullptr; // setting head and tail pointers to nullptr
        Node* tail = nullptr;

        for(int i = 0; i < n; i++){ // this loop is for creating the nodes and connecting them
            cin >> my_char;
            Node* node = new Node(my_char);

            if(head == nullptr){ // if the head pointer is nullptr, set head and tail to node
                head = tail = node; 
            }
            else{
                tail->next = node; // if the head node already exists, 1. connect the tail to a new node
                tail = node; // 2. make the new node the tail
            }

            Node* cur = head; // make the cur pointer that points to head
            my_map[my_char]++;

            while(cur!= nullptr && my_map[cur->data] > 1){
                cur = cur->next;
            }

            if(cur == nullptr){
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