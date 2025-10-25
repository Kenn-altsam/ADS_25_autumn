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

    for(int i = low; i <= high; i++){ // If we didn’t use i - low, the program would try to access temp[i] 
        my_vector[i] = temp[i - low]; // like temp[2], temp[3], etc. — which would be out of range, 
    }                                 // since temp only has elements starting from index 0.
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

    vector<int> my_vector = {1, 23, 91, 95, 62, 72, 10};

    mergeSort(my_vector, 0, my_vector.size() - 1);

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << ' ';
    }

    return 0;
}