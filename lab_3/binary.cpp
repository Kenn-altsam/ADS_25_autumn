#include <iostream>
using namespace std;

int binary_search(int target, int my_array[], int size){ // function of binary search 
    int left = 0; 
    int right = size - 1;
    int mid;

    while(left <= right){ // work while the left is less than or equal to right
        mid = left + (right - left) / 2; // the formula for finding the mid comes from the (right + left) / 2, by adding left and subtracting it from the numerator

        if(my_array[mid] == target){ // if the value at the index 'mid' is equal to the target, return the mid
            return mid;
        }
        else if(my_array[mid] < target){ // if the mid value is less than target, we don't need the left side of the array
            left = mid + 1; // we add +1, because the mid point is not necessary also, after checking
        }
        else{
            right = mid - 1; // if the mid value is greater than target, we don't need the right side of the array
        }
    }

    return -1; // if after the while loop, we didn't find the number, return -1  
}

int main(){

    int size, target, x;
    cin >> size >> target;
    int my_array[size + 5];

    for(int i = 0; i < size; i++){ // get the values of the array
        cin >> x;
        my_array[i] = x;
    }

    int result = binary_search(target, my_array, size); 

    if(result == -1){ // if -1 is returned, print "Not found"
        cout << "Not found";
    }
    else{
        cout << result; // otherwise, print result
    }

    return 0;
}