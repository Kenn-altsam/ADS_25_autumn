// Killua and Hunter exam
// Print the maximum distance between any two vertices in a binary tree.

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
        root = new Node(data);          // // assigning a new node to root with & modifies the actual pointer passed from main()
    }
    else{
        if(data < root->data){ // if the given value is less than the root's data go to the left child
            insert_bst(root->left, data);
        }
        else if(data > root->data){
            insert_bst(root->right, data); // otherwise, go to the right child
        }
    }
}

// The maximum distance between any two vertices in a binary search tree is called the diameter of the tree

// Find the longest path in the left subtree
// Find the longest path in the right subtree
// Find the path that goes through the current node (left_height + right_height + 1)

int cnt = 0;

int diameter(Node* root){ 
    if(root == NULL){
        return 0;
    }
    int left_distance = diameter(root->left); // Find the longest path in the left subtree
    int right_distance = diameter(root->right); // Find the longest path in the right subtree
    
    cnt = max(cnt, left_distance + right_distance); // Checks if the path that goes through me is the longest one we've seen so far.

    return 1 + max(left_distance, right_distance); // Find the height of the current node
}                                                  // Tells parent how long the path is from the parent down through current to the farthest leaf.

int main(){

    long long n, x; 
    cin >> n;

    Node* root = NULL; // creating the first node and setting it's value to NULL;

    for(int i = 0; i < n; i++){ // getting elements for the bst
        cin >> x;
        insert_bst(root, x);
    }

    diameter(root); // get the diameter of the bst
    cout << cnt + 1; // print cnt + 1, because cnt counts the number of edges, the number of nodes is +1 of edgess

    return 0;
}