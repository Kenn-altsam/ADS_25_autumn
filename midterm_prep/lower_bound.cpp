#include <iostream>
#include <vector>
using namespace std;

int lower_bound_(vector<int> my_vector, int target){
    int left = 0;
    int right = my_vector.size() - 1;
    int mid, ans = my_vector.size();

    while(left <= right){
        mid = left + (right - left) / 2;
        
        if(target <= my_vector[mid]){
            ans = mid;
            right = mid - 1;
        }
        else if(target > my_vector[mid]){
            left = mid + 1;
        }
    }

    return ans;
}  

int main(){

    vector<int> my_vector = {1, 10, 20, 25, 72, 91};

    int result = lower_bound_(my_vector, 11);

    cout << result;

    return 0;
}