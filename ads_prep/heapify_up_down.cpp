// #include <iostream>
// #include <vector>
// using namespace std;

// void swap(int &a, int &b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

// void heapify(vector<int> &my_vector, int i){
//     int largest = i;
//     int left_child = 2 * i + 1;
//     int right_child = 2 * i + 2;

//     if(left_child < my_vector.size() && my_vector[left_child] > my_vector[largest]){
//         largest = left_child;
//     }
//     if(right_child < my_vector.size() && my_vector[right_child] > my_vector[largest]){
//         largest = right_child;
//     }

//     if(largest != i){
//         swap(my_vector[largest], my_vector[i]);
//         heapify(my_vector, largest);
//     }
// }

// void insert(vector<int> &my_vector, int a){
//     my_vector.push_back(a);
//     int current = my_vector.size() - 1;

//     while(current > 0){
//         int parent = (current - 1) / 2;
//         if(my_vector[current] > my_vector[parent]){
//             swap(my_vector[current], my_vector[parent]);
//             current = parent;
//         }
//         else{
//             break;
//         }
//     }
// }

// void delete_node(vector<int> &my_vector){

//     if(my_vector.empty()){
//         throw runtime_error("Heap is empty");
//     }
//     int current = 0;
//     int last = my_vector.size() - 1;

//     swap(my_vector[current], my_vector[last]);

//     my_vector.pop_back();
//     int size_ = my_vector.size();

//     if(current < size_){
//         heapify(my_vector, current);
//     }
// }

// int main(){

//     vector<int> my_vector = {10, 2, 29, 5, 32};

//     for(int i = my_vector.size() / 2 - 1; i >= 0; i--){ // we need to start from the (size / 2 - 1)'s node because, everything after it are leaf nodes, and they don't violate the property of the heap
//         heapify(my_vector, i); // we need to heapify every parent node
//     }

//     insert(my_vector, 43);

//     for(int i = 0; i < my_vector.size(); i++){
//         cout << my_vector[i] << ' ';
//     }

//     cout << endl;

//     delete_node(my_vector);

//     for(int i = 0; i < my_vector.size(); i++){
//         cout << my_vector[i] << ' ';
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
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
        return;
    }
    int current = 0;
    int last = my_vector.size() - 1;
    swap(my_vector[current], my_vector[last]);
    my_vector.pop_back();
    
    if(!my_vector.empty()){
        heapify(my_vector, current);
    }
}

int main(){

    vector<int> my_vector = {15, 25, 92, 1, 10, 11};

    for(int i = (my_vector.size() - 1) / 2; i >= 0; i--){
        heapify(my_vector, i);
    }

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << ' ';
    }

    cout << endl;

    insert(my_vector, 100);

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << ' ';
    }

    cout << endl;

    pop(my_vector);

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << ' ';
    }

    return 0;
}