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
                i++;
            }
        }
    }
    return lps;
}

int kmp(const string &text, const string &pattern){
    vector<int> lps = compute_lps(pattern);
    int text_size = text.size(), pattern_size = pattern.size();

    int i = 0, j = 0;

    while(i < text_size){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }

        if(j == pattern_size){
            return i - pattern_size;
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
    return -1;
}

int main(){

    string first, second;

    cin >> first >> second;

    int n = first.size();

    string double_first = first + first;

    int pos = kmp(double_first, second);
    if(pos == -1){
        cout << -1;
        return 0;
    }    
    int shift = (n - pos % n) % n;
    cout << shift;

    return 0;
}