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

void inorder(Node* root, Node* &prev){
    if(root == NULL){
        return;
    }
    inorder(root->left, prev);

    prev->right = root; // link previous to current
    root->left = NULL; // left must be null in the linked list
    prev = root; // move prev forward

    inorder(root->right, prev); 
}

Node* flatten_bst(Node* &root){
    Node dummy(-1);
    Node* prev = &dummy;
    inorder(root, prev);
    return dummy.right; // first real node after dummy
}

void insert_bst(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
        return;
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

    Node* root = NULL;

    for(int i = 0; i < n; i++){
        cin >> x;
        insert_bst(root, x);
    }

    Node* head = flatten_bst(root);

    Node* cur = head;
    
    while(cur != nullptr){
        cout << cur->data << "->";;
        cur = cur->right;
    }

    cout << "NULL";

    return 0;
}