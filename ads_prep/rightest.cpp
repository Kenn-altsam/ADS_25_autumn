#include <iostream>
using namespace std;

int main(){

    int arr[] = {1,2,2,2,3,4,4,5};

    int target = 2;

    int left = 0; 
    int right = sizeof(arr) / sizeof(arr[0]) - 1;
    int mid, ans;

    while(left <= right){
        mid = left + (right - left) / 2;
        if(arr[mid] == target){
            ans = mid;
            left = mid + 1;
        }
        else if(target < arr[mid]){
            right = mid - 1;
        }
        else if(target > arr[mid]){
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}