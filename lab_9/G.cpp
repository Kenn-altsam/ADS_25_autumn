#include <iostream>
#include <vector>
using namespace std;

vector<int> compute_lps(const string &pattern){
    int m = pattern.size();
    vector<int> lps(m, 0);
    int i = 1, j = 0;

    while(i < m){
        if(pattern[i] == pattern[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main(){

    string my_string;
    cin >> my_string;

    vector<int> lps = compute_lps(my_string);

    cout << my_string.size() - lps.back();

    return 0;
}