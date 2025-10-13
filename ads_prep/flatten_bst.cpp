#include <iostream>
using namespace std;

struct LL_node{
    int data;
    LL_node* next;

    LL_node(int new_data){
        data = new_data;
        next = nullptr;
    }
};

struct Node_bst{
    int data;
    Node_bst* left;
    Node_bst* right;

    Node_bst(int new_data){
        data = new_data;
        left = nullptr;
        right = nullptr;
    }
};

void insert_bst(Node_bst* &root, int data){
    if(root == NULL){
        root = new Node_bst(data);
    }

    if(data < root->data){
        insert_bst(root->left, data);
    }
    else{
        insert_bst(root->right, data);
    }
}

int main(){

    int n, x; 
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        insert_bst
    }

    return 0;
}