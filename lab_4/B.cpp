// Get subtree's size

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
    if(root == nullptr){                // we need &root because, we're changing the actual bst itself
        root = new Node(data);          // assigning a new node to root with & modifies the actual pointer passed from main()
        return;
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

int count(Node* root){ // the function for summing the subtree starting from the given root
    if(root == nullptr){
        return 0;
    }
    else{
        return 1 + count(root->left) + count(root->right); // we always start with 1, because we are already in the first element
    }
}

int search(Node* root, int data){ // the function for searching the particular element in the bst
    if(root == nullptr){ // if the given root is equal to nullptr, return 0, meaning that it's a leaf node
        return 0;
    }
    if(data == root->data){ // if data and the root's data are equal, we found the element and we have to find the sum 
        return count(root); // of the elements of the subtree 
    }
    if(data < root->data){ // if the data is less than the root's data, go left 
        return search(root->left, data);
    }
    else{
        return search(root->right, data); // otherwise, go right
    }
    
}

int main(){
    
    int n, m, x;
    cin >> n;

    Node* root = NULL; // creating the first node and setting it's value to NULL;

    for(int i = 0; i < n; i++){ // getting elements for the bst
        cin >> x;
        insert_bst(root, x);
    }

    cin >> m;

    Node* cur = root;

    cout << search(cur, m);

    return 0;
}