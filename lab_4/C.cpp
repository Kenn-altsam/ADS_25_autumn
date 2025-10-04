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

vector<int> my_vector;

int count(Node* cur){
    if(cur == nullptr){
        return 0;
    }
    else{
        my_vector.push_back(cur->data);
        return count(cur->left) + count(cur->right);;
    }
}

int search_and_add_to_vector(Node* cur, int data){
    if(cur == nullptr){
        return 0;
    }
    else if(data == cur->data){
        return count(cur);
    }
    else if(data < cur->data){
        return search_and_add_to_vector(cur->left, data);
    }
    else{
        return search_and_add_to_vector(cur->right, data);
    }
}

void insert_bst(Node* &root, int data){
    if(root == nullptr){
        root = new Node(data);
        return;
    }
    else{
        if(data < root->data){
            insert_bst(root->left, data);
        }
        else{
            insert_bst(root->right, data);
        }
    }
}

int main(){

    int n, m, x;
    
    cin >> n;

    Node* root = NULL;

    for(int i = 0; i < n; i++){
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