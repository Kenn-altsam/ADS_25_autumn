#include <iostream>
#include <vector>
using namespace std;

vector<int> construct_lps(const string &pattern){
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
                lps[i] = j;
                i++;
            }
        }
    }
    return lps;
}

int kmp(const string &text, const string &pattern){
    vector<int> lps = construct_lps(pattern);
    int text_size = text.size(), pattern_size = pattern.size();
    vector<int> result;

    int i = 0, j = 0;

    while(i < text_size){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }

        if(j == pattern_size){
            result.push_back(j - pattern_size);
            j = lps[j - 1];
        }
        else if(i < text_size && text[i] != pattern[j]){
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    return result.size();
}

int main(){

    int times, k;
    string my_string;
    cin >> times;

    vector<int> my_vector;

    for(int i = 0; i < times; i++){
        cin >> my_string >> k;
        vector<int> lps = construct_lps(my_string);
        int n = my_string.size();
        
        int len_sps = n - lps[n - 1];

        int min_length = n + (k - 1) * len_sps;

        my_vector.push_back(min_length);
    }

    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] << endl;
    }

    return 0;
}