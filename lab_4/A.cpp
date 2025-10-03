// You are going to hike in the mountains.You need to tell which of the paths written on the piece of paper is available.

#include <iostream>
#include <vector>
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

void insert_bst(Node* &node, int data){
    if(node == nullptr){
        node = new Node(data);
    }
    else{
        if(data < node->data){
            insert_bst(node->left, data);
        }
        else{
            insert_bst(node->right, data);
        }
    }
}

bool check_function(string my_string, Node* node){
    Node* cur = node;
    for(int i = 0; i < my_string.size(); i++){
        if(cur == nullptr){
            return false;
        }
        else if(my_string[i] == 'L'){
            cur = cur->left;
        }
        else if(my_string[i] == 'R'){
            cur = cur->right;
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
    string my_str;
    vector<string> my_vector;

    cin >> n >> m;

    Node* root = NULL;

    for(int i = 0; i < n; i++){
        cin >> x;
        insert_bst(root, x);
    }

    for(int i = 0; i < m; i++){
        cin >> my_str;
        my_vector.push_back(my_str);
    }

    for(int i = 0; i < m; i++){
        if(check_function(my_vector[i], root)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}