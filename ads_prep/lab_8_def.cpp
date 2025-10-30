#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &my_vector, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high){
        if(my_vector[left] > my_vector[right]){
            temp.push_back(my_vector[left]);
            left++;
        }
        else{
            temp.push_back(my_vector[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(my_vector[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(my_vector[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        my_vector[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &my_vector, int low, int high){
    if(low == high){
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(my_vector, low, mid);
    mergeSort(my_vector, mid + 1, high);
    merge(my_vector, low, mid, high);
}

int main(){

    vector<int> first = {1, 24, 55, 64, 91, 101, 102, 103, 105};
    vector<int> second = {2, 60, 70, 91, 100};

    vector<int> temp;

    int left = 0;
    int right = 0;

    for(int i = 0; i < first.size(); i++){
        temp.push_back(first[i]);
    }

    for(int i = 0; i < second.size(); i++){
        temp.push_back(second[i]);
    }

    mergeSort(temp, 0, temp.size() - 1);

    for(int i = 0; i < temp.size(); i++){
        cout << temp[i] << ' ';
    }

    // while(left <= (first.size() - 1) && right <= (second.size() - 1)){
    //     if(first[left] > second[right]){
    //         temp.push_back(first[left]);
    //         left++;
    //     }
    //     else{
    //         temp.push_back(second[right]);
    //         right++;
    //     }
    // }

    // while(left <= (first.size() - 1)){
    //     temp.push_back(first[left]);
    //     left++;
    // }

    // while(right <= (second.size() - 1)){
    //     temp.push_back(second[right]);
    //     right++;
    // }

    // for(int i = 0; i < temp.size(); i++){
    //     cout << temp[i] << ' ';
    // }

    return 0;
}