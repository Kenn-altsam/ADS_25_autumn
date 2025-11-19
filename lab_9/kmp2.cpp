#include <iostream>
using namespace std;

vector<int> compute_lps(const string &pattern){
    int m = pattern.size();
    vector<int> lps(m, 0);
    int j = 0, i = 1;

    while(i < pattern.size()){
        if(pattern[i] == pattern[j]){
            i++;
            j++;
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
    vector<int> result;

    int text_size = text.size(), pattern_size = pattern.size();
    int i = 0, j = 0;

    while(i < text_size){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }

        if(j == pattern_size){
            result.push_back(i - pattern_size);
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

    string text, pattern;
    cin >> text >> pattern;

    vector<int> my_vector = kmp(text, pattern);
    for(int i = 0; i < my_vector.size(); i++){
        cout << my_vector[i] + 1 << ' ';
    }

    return 0;
}