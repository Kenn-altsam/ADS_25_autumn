#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> my_vector, int target){
    int left = 0;
    int right = my_vector.size() - 1;
    int mid;

    while(left <= right){
        mid = left + (right - left) / 2;
        if(my_vector[mid] == target){
            return mid;
        }
        else if(my_vector[mid] < target){
            left = mid + 1;
        }
        else if(my_vector[mid] > target){
            right = mid - 1;
        }
    }
    return -1;
}

int main(){

    vector<int> my_vector = {1, 8, 10, 20, 30, 35, 91};

    int result = binary_search(my_vector, 20);

    cout << result;

    return 0;
}