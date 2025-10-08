// insert x
// delete x
// cnt x

// The functions are already given in the problem definition

#include <iostream>
#include <map>
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

Node* getMin(Node* root){
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}

Node* add(Node* root, int data){
	if (root == NULL){
		return new Node(data);
	} 
    else if(data < root->data){
		if(root->left == NULL){
			root->left = new Node(data);
		} 
        else{
			root->left = add(root->left, data);
		}
	} 
    else if(data > root->data){
		if(root->right == NULL){
			root->right = new Node(data);
		} 
        else{
			root->right = add(root->right, data);
		}
	}
	return root;
}

Node* deleteNode(Node* root, int data){
	if (root == NULL){
		return NULL;
	} 
    else if(data < root->data){
		root->left = deleteNode(root->left, data);
		return root;
	} 
    else if(data > root->data){
		root->right = deleteNode(root->right, data);
		return root;
	} 
    else{ // if the we find the node that we want to delete
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}
        else if(root->right == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		} 
        else if(root->left == NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		} 
        else{
			Node* temp = getMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
}

Node* find(Node* root, int x){
	if (root == NULL){
		return NULL;
	} 
    else if(root->data == x){
		return root;
	} 
    else if(root->data < x){
		return find(root->right, x);
	} 
    else{
		return find(root->left, x);
	}
}

int main(){

    int n, x;
    cin >> n;
    map<int, int> my_map;

    string command;

    Node* root = NULL;

    for(int i = 0; i < n; i++){
        cin >> command >> x;
        if(command == "insert"){ // if the command is insert -> insert the element to the bst and increase 
            add(root, x);        // it's occurrence in the map
            my_map[x]++;
        }
        else if(command == "delete"){ // if the command is delete -> delete the element to the bst and decrease 
            deleteNode(root, x);      // it's occurrence in the map
            my_map[x]--;
        }
        else if(command == "cnt"){ // if the command is cnt -> print the occurrence of the element in the map
            cout << my_map[x] << endl;
        }
    }

    return 0;
}