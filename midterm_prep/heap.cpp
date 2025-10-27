#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int> &my_vector, int i){
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if(left_child < my_vector.size() && my_vector[left_child] > my_vector[largest]){
        largest = left_child;
    }
    if(right_child < my_vector.size() && my_vector[right_child] > my_vector[largest]){
        largest = right_child;
    } 

    if(largest != i){
        swap(my_vector[largest], my_vector[i]);
        heapify(my_vector, largest);
    }
}

void insert(vector<int> &my_vector, int a){
    my_vector.push_back(a);
    int current = my_vector.size() - 1;

    while(current > 0){
        int parent = (current - 1) / 2;

        if(my_vector[current] > my_vector[parent]){
            swap(my_vector[current], my_vector[parent]);
            current = parent;
        }
        else{
            break;
        }
    }
}

void pop(vector<int> &my_vector){

    if(my_vector.empty()){
        cout << "Heap is empty";
    }

    int last = my_vector.size() - 1;

    swap(my_vector[0], my_vector[last]);
    my_vector.pop_back();

    if(!my_vector.empty()){
        heapify(my_vector, 0);
    }
}

int main(){

    vector<int> my_vector = {1, 29, 94, 91, 63, 12, 10};

    for(int i = (my_vector.size() - 1) / 2; i >= 0; i--){
        heapify(my_vector, i);
    }

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << ' ';
    }
    cout << endl;

    insert(my_vector, 25);

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << ' ';
    }
    cout << endl;

    pop(my_vector);

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << ' ';
    }
    cout << endl;

    return 0;
}