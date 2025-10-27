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

void insert_bst(Node* &root, int x){
    if(root == NULL){
        root = new Node(x);
    }
    if(x < root->data){
        insert_bst(root->left, x);
    }
    else if(x > root->data){
        insert_bst(root->right, x);
    }
}

void inorder(Node* root, vector<int> &result){
    if(root == NULL){
        return;
    }
    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result);
}

int main(){

    vector<int> my_vector = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    Node* root = NULL;

    for(int i = 0; i < my_vector.size(); i++){
        insert_bst(root, my_vector[i]);
    }

    vector<int> result;

    inorder(root, result);

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << ' ';
    }

    return 0;
}