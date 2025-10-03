#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n, k, l1, r1, l2, r2, cnt;

    cin >> n >> k;

    vector<int> L2, R2;

    for(int i = 0; i < n; i++){
        cin >> l1 >> r1 >> l2 >> r2;
        L2.push_back(l2);
        R2.push_back(r2);
    }

    int left = 1;
    int right = 1000000000;
    int mid, ans = 0;

    while(left <= right){
        mid = left + (right - left) / 2;
        cnt = 0;

        for(int i = 0; i < n; i++){
            if(L2[i] <= mid && R2[i] <= mid){
                cnt++;
            }
        }

        if(cnt >= k){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}