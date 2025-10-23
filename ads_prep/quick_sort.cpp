#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int my_array[], int low, int high){
    int pivot = my_array[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(my_array[j] <= pivot){
            i++;
            swap(my_array[i], my_array[j]);
        }
    }
    swap(my_array[i + 1], my_array[high]);
    return i + 1;
}

void quick_sort(int my_array[], int low, int high){
    if(low < high){
        int pi = partition(my_array, low, high);
        quick_sort(my_array, low, pi - 1);
        quick_sort(my_array, pi + 1, high);
    }
}

int main(){

    int my_array[] = {8, 7, 6, 1, 0, 9, 2};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    quick_sort(my_array, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << my_array[i] << ' ';
    }

    return 0;
}