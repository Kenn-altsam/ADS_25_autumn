// simple binary search

#include <iostream>
using namespace std;

int main(){

    int n, x, target;
    cin >> n;

    int my_array[n + 5];

    for(int i = 0; i < n; i++){
        cin >> x;
        my_array[i] = x;
    }

    cin >> target;

    int left = 0;
    int right = n - 1;
    int mid;

    bool exists = false;

    while(left <= right){
        mid = left + (right - left) / 2;

        if(my_array[mid] == target){
            cout << "Yes";
            exists = true;
            break;
        }
        else if(my_array[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    if(exists == false){
        cout << "No";
    }

    return 0;
}