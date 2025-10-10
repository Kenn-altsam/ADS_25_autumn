#include <iostream>
#include <vector>
using namespace std;

int binary(const vector<int> &arr, int target){
    int left = 0;
    int right = arr.size() - 1;
    int mid;

    while(left <= right){
        mid = left + (right - left) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if(target > arr[mid]){
            left = mid + 1;
        }
        else if(target < arr[mid]){
            right = mid - 1;
        }
    }

    return -1;
}

int main(){

    int n, target, x;
    vector<int> my_vector;

    cin >> n >> target;

    for(int i = 0; i < n; i++){
        cin >> x;
        my_vector.push_back(x);
    }

    cout << binary(my_vector, target);

    return 0;
}