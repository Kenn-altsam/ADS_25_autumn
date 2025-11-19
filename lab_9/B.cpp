#include <iostream>
#include <vector>
using namespace std;

vector<int> compute_lps(const string &pattern){
    int m = pattern.size();
    int i = 1, j = 0;
    vector<int> lps(m, 0);

    while(i < m){
        if(pattern[i] == pattern[j]){
            i++;
            lps[i] = j;
            j++;
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

int cnt = 0;

void kmp(const string &text, const string &pattern){
    vector<int> lps = compute_lps(pattern);

    int text_size = text.size(), pattern_size = pattern.size();
    int i = 0, j = 0;

    while(i < text_size){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }

        if(j == pattern_size){
            cnt++;
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
}

int main(){

    string text, pattern;
    int times;

    cin >> pattern >> times >> text;

    kmp(text, pattern);

    if(cnt >= times){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}