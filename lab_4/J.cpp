// Balanced Binary Search Tree
// Sort the array, create a bst using indexes, print the bst with preorder traversal

#include <iostream>
#include <algorithm>
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

void print(Node* root){ // preorder traversal -> printing the root and then going to the left and right childs
    if(root == NULL){
        return;
    }
    cout << root->data << ' ';
    print(root->left);
    print(root->right);
}

Node* create(int my_array[], int left_, int right_){ // creating the bst
    if(left_ > right_){ // if the left index is greater than right index, return NULL
        return NULL;
    }
    int mid = left_ + (right_ - left_) / 2; // Find the middle element of the current list segment

    Node* root = new Node(my_array[mid]); // Make the mid element the root of its subarray

    root->left = create(my_array, left_, mid - 1); // Recursively build the left subtree using the left half of the list
    root->right = create(my_array, mid + 1, right_); // Recursively build the right subtree using the right half of the list

    return root;
}

int main(){

    int n = 1, x, t;
    cin >> t;

    int my_array[33000]; // an array for saving the values at the given index

    for(int i = 1; i <= t; i++){ // we have (2^n - 1) elements, so we find this total amount of n
        n *= 2;
    }
    n--;

    for(int i = 1; i <= n; i++){ // getting elements from the input
        cin >> x;
        my_array[i] = x;
    }

    sort(my_array + 1, my_array + n + 1); // ignoring the 0th index, and sorting the array starting from index 1 
                                          // until array's (n + 1)st element
    print(create(my_array, 1, n)); // creating the bst and printing it in the preorder

    return 0;
}