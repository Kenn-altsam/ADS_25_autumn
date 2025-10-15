#include <iostream>
using namespace std;

int lower_bound(vector<int> my_vector, int target){
    int left = 0;
    int right = my_vector.size();
    int mid, ans = my_vector.size();

    while(left <= right){
        mid = left + (right - left) / 2;

        if(target <= my_vector[mid]){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1; 
        }
    }

    return ans;
}

int upper_bound(vector<int> my_vector, int target){
    int left = 0;
    int right = my_vector.size();
    int mid, ans = my_vector.size();

    while(left <= right){
        mid = left + (right - left) / 2;

        if(target < my_vector[mid]){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1; 
        }
    }

    return ans;
}


int main(){

    in

    return 0;
}