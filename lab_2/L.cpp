#include <iostream>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int new_data){
        data = new_data;
        next = nullptr;
    }
};

int findMaxSum(int n, Node* head){

    int mx = INT_MIN, sum;
    Node* cur = head;
    for(int i = 0; i < n; i++){
        sum = 0;
        cur = head;
        head = head->next;
        while(cur != nullptr){
            sum += cur->data;
            if(sum > mx){
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

    cout << findMaxSum(n, head);

    return 0;
}