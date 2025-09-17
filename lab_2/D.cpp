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

    int n, x;

    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0; i < n; i++){
        cin >> x;

        Node* node = new Node(x);

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
        // Miras, Miras, Kenzhe, Olzhas, Olzhas, Sanzhar
    }

    return 0;
}