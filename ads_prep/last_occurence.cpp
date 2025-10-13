#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> my_vector;

    int n, x, target;
    cin >> n >> target;

    for(int i = 0; i < n; i++){
        cin >> x;
        my_vector.push_back(x);
    }

    sort(my_vector.begin(), my_vector.end());

    int left = 0;
    int right = my_vector.size() - 1;
    int mid, ans;

    while(left <= right){
        mid = left + (right - left) / 2;
        
        if(my_vector[mid] == target){
            ans = mid;
            left = mid + 1;
        }
        else if(my_vector[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}