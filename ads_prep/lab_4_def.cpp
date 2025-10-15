#include <iostream>
#include <vector>
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



void insert_bst(Node* &root, int x){
    if(root == NULL){
        root = new Node(x);
    }
    if(x < root->data){
        insert_bst(root->left, x);
    }
    else if(x > root->data){
        insert_bst(root->right, x);
    }
}

int sum = 0;
void inorder(Node* root){
    if(root == nullptr){
        return;
    }
    if(root->right){
        sum += root->right->data;
    }
    inorder(root->left);

    inorder(root->right);
}

int main(){

    int n, x;
    cin >> n;

    Node* root = nullptr;

    for(int i = 0; i < n; i++){
        cin >> x;
        insert_bst(root, x);
    }

    inorder(root);

    cout << sum;

    return 0;
}