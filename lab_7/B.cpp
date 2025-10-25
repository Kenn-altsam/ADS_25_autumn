#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &my_vector, int low, int mid, int high){
    vector<int> temp;
    int left = low; 
    int right = mid + 1;

    while(left <= mid && right <= high){
        if(my_vector[left] < my_vector[right]){
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

    int first, second, x;
    vector<int> first_vector, second_vector;

    cin >> first;

    for(int i = 0; i < first; i++){
        cin >> x;
        first_vector.push_back(x);
    }

    cin >> second;

    for(int i = 0; i < second; i++){
        cin >> x;
        second_vector.push_back(x);
    }

    mergeSort(first_vector, 0, first_vector.size() - 1);
    mergeSort(second_vector, 0, second_vector.size() - 1);

    vector<int> result;

    int left = 0, right = 0;

    while(left < first_vector.size() && right < second_vector.size()){
        if(first_vector[left] < second_vector[right]){
            result.push_back(first_vector[left]);
            left++;
        }
        else{
            result.push_back(second_vector[right]);
            right++;
        }
    }

    while(left < first_vector.size()){
        result.push_back(first_vector[left]);
        left++;
    }

    while(right < second_vector.size()){
        result.push_back(second_vector[right]);
        right++;
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << ' ';
    }

    return 0;
}