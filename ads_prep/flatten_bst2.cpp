#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left; 
    Node* right;

    Node(int new_data){
        data = new_data;
        left = nullptr;
        right = nullptr;
    }
};

struct Node2{
    int data;
    Node2* next;

    Node2(int new_data){
        data = new_data;
        next = nullptr;
    }
};

void insert_bst(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
        return;
    }

    if(data < root->data){
        insert_bst(root->left, data);
    }
    else if(data > root->data){
        insert_bst(root->right, data);
    }
}

Node2* head = nullptr;
Node2* tail = nullptr;

Node2* inorder(Node* root){
    if(root == NULL){
        return head;
    }

    inorder(root->left);

    Node2* node = new Node2(root->data);
    if(head == nullptr){
        head = tail = node;
    }
    else{
        tail->next = node;
        tail = node;
    }

    inorder(root->right);

    return head;
}

int main(){

    int n, x;
    cin >> n;

    Node* root = NULL;  

    for(int i = 0; i < n; i++){
        cin >> x;
        insert_bst(root, x);
    }

    Node2* head = inorder(root);
    Node2* cur = head;

    while(cur != nullptr){
        cout << cur->data << "->";
        cur = cur->next;
    }

    cout << "NULL";

    return 0;
}