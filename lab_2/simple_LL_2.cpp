#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int new_data){
        data = new_data;
        next = nullptr;
    }
};

int main(){

    int x;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0; i < 6; i++){
        Node* node = new Node(i + 1);
        if(head == nullptr){
            head = tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
    }

    Node* cur = head;

    while(cur != nullptr){
        cout << cur->data << " -> ";
        cur = cur->next;
    }

    cout << "NULL";

    return 0;
}