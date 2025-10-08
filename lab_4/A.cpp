// You're going to hike in the mountains.You need to tell which of the paths written on the piece of paper is available.

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

Node* insert_bst(Node* &root, int data){ // inserting the elements to the bst
    if(root == nullptr){                 // we need &root because, we're changing the actual bst itself
        root = new Node(data);           // assigning a new node to root with & modifies the actual pointer passed from main()
    }
    else{
        if(data < root->data){ // if the given value is less than the root's data go to the left child
            insert_bst(root->left, data);
        }
        else{
            insert_bst(root->right, data); // otherwise, go to the right child
        }
    }
    return root;
}

bool is_valid(Node* cur, string my_string){
    
    for(int i = 0; i < my_string.size(); i++){ // working with every letter of the string
        if(cur == nullptr){ // if the cur is nullptr, return false
            return false;
        }
        else{
            if(my_string[i] == 'L'){ // if the there's something in the cur's data, then we compare the letter
                cur = cur->left;     // of my_string with the cur's data - if it's less, go left
            }
            else if(my_string[i] == 'R'){ // if it's greater, go right
                cur = cur->right;
            }
        }
    }

    if(cur != NULL){ // if after all the operations we end up at the real node that is not NULL, 
        return true; // meaning that there is an existing peak, return true
    }
    else{
        return false;
    }
}

int main(){

    int n, m, x;
    cin >> n >> m;

    string my_string;

    Node* root = NULL; // creating the first node and setting it's value to NULL;

    vector<string> result;

    for(int i = 0; i < n; i++){ // getting elements for the bst
        cin >> x;
        insert_bst(root, x);
    }

    for(int i = 0; i < m; i++){
        cin >> my_string;

        if(is_valid(root, my_string)){ // if the string is valid, push it to the vector
            result.push_back("YES");
        }
        else{
            result.push_back("NO");
        }
    }

    for(int i = 0; i < result.size(); i++){ // print all the values of the vector;
        cout << result[i] << endl;
    }

    return 0;
}