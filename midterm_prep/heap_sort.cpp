#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int> &my_vector, int n, int i){
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

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

void heap_sort(vector<int> &my_vector){

    int n = my_vector.size();

    for(int i = (my_vector.size() - 1) / 2; i >= 0; i--){
        heapify(my_vector, my_vector.size(), i);
    }

    for(int i = n - 1; i > 0; i--){
        swap(my_vector[i], my_vector[0]);
        heapify(my_vector, i, 0);
    }
}

int main(){

    vector<int> my_vector = {1, 10, 29, 30, 51, 91, 60};

    heap_sort(my_vector);

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << " ";
    }

    return 0;
}