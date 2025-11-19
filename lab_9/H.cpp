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

vector<int> kmp(const string &text, const string &pattern){
    vector<int> lps = compute_lps(pattern);
    int text_size = text.size(), pattern_size = pattern.size();
    int i = 0, j = 0; 
    vector<int> result;

    while(i < text_size){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }

        if(j == pattern_size){
            result.push_back(j - pattern_size);
            j = lps[j - 1];
        }
        else if(text[i] != pattern[j]){
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    return result;
}

int main(){

    string my_string;
    cin >> my_string;

    int n = my_string.size();

    vector<int> lps = compute_lps(my_string);
    int ans = 0;

    if(n < 3){
        cout << 0;
        return 0;
    }

    for(int i = 1; 2 * i < n; i++){
        int k = 2 * i - 1;
        int L = 2 * i;

        int lps_val = lps[k];

        int T = L - lps_val;

        if(i % T == 0){
            ans++;
        }
    }

    cout << ans;

    return 0;
}