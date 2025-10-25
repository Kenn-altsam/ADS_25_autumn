#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum(vector<int> my_vector){
    int sum_ = 0;
    for(int i = 0; i < my_vector.size(); i++){
        sum_ += my_vector[i];
    }
    return sum_;
}

bool comparison(vector<int> a, vector<int> b){

    int a_sum = sum(a);
    int b_sum = sum(b);

    if(a_sum != b_sum){
        return a_sum > b_sum;
    }
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            return a[i] < b[i];
        }
    }

    return false;
}

int main(){

    int n, m, x;
    cin >> n >> m;

    vector< vector<int> > my_vector;
    vector<int> temp;

    for(int i = 0; i < n; i++){
        temp.clear();
        for(int j = 0; j < m; j++){
            cin >> x;
            temp.push_back(x);
        }
        my_vector.push_back(temp);
    }

    sort(my_vector.begin(), my_vector.end(), comparison);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << my_vector[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}