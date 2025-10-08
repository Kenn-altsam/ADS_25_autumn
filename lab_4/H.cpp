// 8 15 21 26 30 33 35 36 36
// Print the nodes starting from the rightest in a decreasing order

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

void insert_bst(Node* &root, int data){ // inserting the elements to the bst
    if(root == NULL){                   // we need &root because, we're changing the actual bst itself
        root = new Node(data);          // assigning a new node to root with & modifies the actual pointer passed from main()
    }
    else{
        if(data < root->data){ // if the given value is less than the root's data go to the left child
            insert_bst(root->left, data);
        }
        else if(data > root->data){ // otherwise, go to the right child
            insert_bst(root->right, data);
        }
    }
}

int sum = 0;

void inorder(Node* root){ 
    if(root == NULL){ // if the node is empty return nothing
        return;
    }
    inorder(root->right); // visit the right node
    sum += root->data; // sum the data of the current node
    cout << sum << ' '; // print the current node 
    inorder(root->left); // visit the left node
}

int main(){

    int n, x; 
    cin >> n;

    Node* root = NULL; // creating the first node and setting it's value to NULL;

    for(int i = 0; i < n; i++){ // getting elements for the bst
        cin >> x;
        insert_bst(root, x);
    }

    inorder(root); // traversing the bst with inorder, but with first visiting right node, then the node itself
                   // then the left node 
    return 0;
}