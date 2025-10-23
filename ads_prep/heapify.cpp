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
        swap(my_vector[i], my_vector[largest]);
        heapify(my_vector, largest);
    }
}

void insert(vector<int> &my_vector, int a){
    my_vector.push_back(a);
    int current = my_vector.size() - 1;

    if()
}

int main(){

    vector<int> my_vector = {1, 91, 10, 20, 64, 23};

    for(int i = (my_vector.size() - 1) / 2; i >= 0; i--){
        heapify(my_vector, 0);
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
    cout << endl;

    return 0;
}