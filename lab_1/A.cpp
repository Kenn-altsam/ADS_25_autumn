#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){

    deque<int> dq;

    int times;

    cin >> times;

    vector<string> my_vector;
    string res;

    while(times--){
        int n;
        cin >> n;

        for(int i = n; i >= 1; i--){
            dq.push_front(i);

            for(int j = 0; j < i; j++){
                int temp_num = dq.back();
                dq.pop_back();
                dq.push_front(temp_num);
            }
        }

        res = "";

        for(int elem : dq){
            res += (to_string(elem) + " ");
        }
        my_vector.push_back(res);

        dq.clear();
    }

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << "\n";
    }

    return 0;
}
