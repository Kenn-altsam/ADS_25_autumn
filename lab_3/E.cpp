// Material for paddock costs money, so Jonathan wants to
// minimize the length of paddock side. He is not very good at math, help him find this length.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n, k, l1, r1, l2, r2, cnt;

    cin >> n >> k;

    vector<int> L2, R2;

    for(int i = 0; i < n; i++){ // get the coords of the sheep-pasture
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

        for(int i = 0; i < n; i++){ // count for every sheep
            if(L2[i] <= mid && R2[i] <= mid){ // if the height and width of the sheep's square are both less or equal to mid
                cnt++;                        // increase the cnt
            }
        }

        if(cnt >= k){ // if the cnt is greater or equal to k, we save the result of mid to ans, and search forward by decreasing the right, because we need minimal 
            ans = mid; // mid is the length of the paddock's square
            right = mid - 1;
        }
        else{ // if it's not enough, increase the left
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}