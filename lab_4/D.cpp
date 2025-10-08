// Print the maximum level in bst and print the sum of the elements at each level in bst

#include <iostream>
#include <vector>
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
            insert_bst(root->left, data);       // the nodes are connected with each other when we call the function with
        }                                       // or root->left or root->right, this way the root->left will point to the
        else{                                   // or root->left or root->right, this way the root->left will point to the
            insert_bst(root->right, data); // otherwise, go to the right child
        }
    }
}

int sum[5000];
int max_level = 0;

void find_level(Node* root, int level){ // finding the sum of each level 
    if(root == NULL){
        return;
    }
    sum[level] += root->data; // adding the data of each node to its index in the array
    find_level(root->left, level + 1); // go to the left child 
    find_level(root->right, level + 1); // and right child
    max_level = max(max_level, level); // max_level is found when we reach the last level in a bst and start backtracking
}                                      // at this place the level variable has the maximum value and when going upward
                                       // in a recursion the level will decrease and max_level will stay the same
int main(){

    int n, x;
    cin >> n;

    Node* root = NULL; // creating the first node and setting it's value to NULL;

    for(int i = 0; i < n; i++){ // getting elements for the bst
        cin >> x;
        insert_bst(root, x);
    }

    find_level(root, 1); // calling the find_level function, which already finds max level and saves results to the array
    cout << max_level << endl;

    for(int i = 1; i <= max_level; i++){ // printing the sums of each level
        cout << sum[i] << ' ';
    }

    return 0;
}