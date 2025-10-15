// Write a program that outputs the coordinates of elements from an array of size n×m, which is filled like
// snake. Snake array - which is filled in like this
// • For all j and k (j < k): aij > a(i+1)j.
// • If i is even then, for all j and k (j < k) : a[i][j] > a[i][k].
// • If i is odd then, for all j and k (j < k) : a[i][j] < a[i][k].

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int binary_search(int target, int my_array[], int size){ // binary search function
    int left = 0;
    int right = size - 1;
    int mid;

    while(left <= right){
        mid = left + (right - left) / 2;

        if(my_array[mid] == target){
            return mid;
        }
        else if(my_array[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return -1;
}

int main(){

    int t, n, m, x;

    cin >> t;

    int tests[t + 5];

    for(int i = 0; i < t; i++){ // getting numbers that we need to search
        cin >> x;
        tests[i] = x;
    }

    cin >> n >> m;

    map<int, pair<int, int>> my_map; // this map is for saving the coords of numbers in 2D array

    int array_2D[n][m];

    int my_array[n * m + 5];

    int index = 0;

    for(int i = 0; i < n; i++){ // getting the 2D array
        for(int j = 0; j < m; j++){
            cin >> x;
            my_map[x] = {i, j};
            my_array[index++] = x;
        }
    }

    sort(my_array, my_array + (n * m));

    for(int i = 0; i < t; i++){
        int res = binary_search(tests[i], my_array, n * m);
        
        if(res == -1){
            cout << -1 << endl;
        }
        else{
            cout << my_map[tests[i]].first << ' ' << my_map[tests[i]].second << endl;
        }
    }

    return 0;
}