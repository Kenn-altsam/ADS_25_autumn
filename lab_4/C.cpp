// Print the subtree of the given node

#include <iostream>
#include <vector>
using namespace std;

vector<int> my_vector;

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
    }
    else{
        if(data < root->data){ // if the given value is less than the root's data go to the left child
            insert_bst(root->left, data);       // the nodes are connected with each other when we call the function with
        }                                       // or root->left or root->right, this way the root->left will point to the
        else{                                   // new node that is created inside the new call of the insert_bst function 
            insert_bst(root->right, data); // otherwise, go to the right child
        }
    }
}

int traverse(Node* root){ // the function for visiting and printing the elements of a subtree starting from the given root
    if(root == nullptr){
        return 0;
    }
    else{
        my_vector.push_back(root->data); // adding elements to the vector
        return traverse(root->left) + traverse(root->right); // going left and right from the current node
    }
}

int search_and_add_to_vector(Node* root, int data){ // the function for searching the particular element in the bst and calling the traverse function
    if(root == nullptr){                            
        return 0;
    }
    if(data == root->data){ // if data and the root's data are equal, we found the element and we have to call the traverse function
        return traverse(root); 
    }
    else if(data < root->data){ // if the data is less than the root's data, go left 
        return search_and_add_to_vector(root->left, data);
    }
    else{
        return search_and_add_to_vector(root->right, data); // otherwise, go right
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

    search_and_add_to_vector(cur, m);
    
    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << ' ';
    }

    return 0;
}