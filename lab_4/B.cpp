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

void insert_bst(Node* &root, int data){
    if(root == nullptr){
        root = new Node(data);
        return;
    }
    else{
        if(data < root->data){
            insert_bst(root->left, data);
        }
        else{
            insert_bst(root->right, data);
        }
    }
}

int count(Node* cur){
    int cnt = 1;
    if(cur == nullptr){
        return 0;
    }
    else{
        return cnt + count(cur->left) + count(cur->right);
    }
}

int search(Node* cur, int data){
    if(cur == nullptr){
        return 0;
    }
    else if(cur->data == data){
        return count(cur);
    }
    else if(data < cur->data){
        return search(cur->left, data);
    }
    else{
        return search(cur->right, data);
    }
}

int main(){

    int n, m, x;
    cin >> n;

    Node* root = NULL;

    for(int i = 0; i < n; i++){
        cin >> x;
        insert_bst(root, x);
    }

    cin >> m;

    Node* cur = root;

    cout << search(cur, m);

    return 0;
}