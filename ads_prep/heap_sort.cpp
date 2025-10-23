#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int> &my_vector, int n, int i){
    int largest = i;
    int left_child = i * 2 + 1;
    int right_child = i * 2 + 2;

    if(left_child < n && my_vector[left_child] > my_vector[largest]){
        largest = left_child;
    }
    if(right_child < n && my_vector[right_child] > my_vector[largest]){
        largest = right_child;
    }

    if(largest != i){
        swap(my_vector[largest], my_vector[i]);
        heapify(my_vector, n, largest);
    }
}

void heapsort(vector<int> &my_vector){
    int n = my_vector.size();
    for(int i = (my_vector.size() - 1) / 2; i >= 0; i--){
        heapify(my_vector, n, i);
    }

    for(int i = n - 1; i > 0; i--){
        swap(my_vector[0], my_vector[i]);
        heapify(my_vector, i, 0);
    }
}

int main(){

    vector<int> my_vector = { 9, 4, 3, 8, 10, 2, 5 };

    heapsort(my_vector);

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << ' ';
    }

    return 0;
}