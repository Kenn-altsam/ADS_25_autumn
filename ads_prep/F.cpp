// Print the number of mini-triangles in resulting Binary Search Tree.

#include <iostream>
using namespace std;

struct Node{ // the struct for the bst
    int data;
    Node* left;
    Node* right;

    Node(int new_data){
        data = new_data;
        left = nullptr;
        right = nullptr;
    }
};

void insert_bst(Node* &root, int data){ // the struct for the bst
    if(root == NULL){                   // we need &root because, we're changing the actual bst itself
        root = new Node(data);          // assigning a new node to root with & modifies the actual pointer passed from main()
    }
    else{
        if(data < root->data){ // if the given value is less than the root's data go to the left child
            insert_bst(root->left, data);
        }
        else{
            insert_bst(root->right, data); // otherwise, go to the right child
        }
    }
}

int cnt = 0; 

void traverse(Node* cur){ 
    if(cur == NULL){ // if the node is empty, return nothing
        return;
    }
    else{
        if(cur->left != NULL && cur->right != NULL){ // if the node has both left and right child nodes
            cnt++;                                   // increment cnt
        }
        traverse(cur->left); // go to the left child
        traverse(cur->right); // go to the right child
    }
}

int main(){

    int n, x;
    cin >> n;

    Node* root = NULL; // creating the first node and setting it's value to NULL;

    for(int i = 0; i < n; i++){ // getting elements for the bst
        cin >> x;
        insert_bst(root, x);
    }

    traverse(root); // finding the number of small triangles

    cout << cnt;

    return 0;
}