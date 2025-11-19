#include <iostream>
#include <vector>
#include <string> 
using namespace std;

vector<int> compute_lps(const string &pattern){
    int m = pattern.size();
    int i = 1, j = 0;
    vector<int> lps(m, 0);

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

bool kmp(const string &text, const string &pattern){
    vector<int> lps = compute_lps(pattern);
    int text_size = text.size(), pattern_size = pattern.size();

    int i = 0, j = 0;

    while(i < text_size){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }

        if(j == pattern_size){
            return true;
        }
        else if(i < my_text && text[i] != pattern[j]){
            if(j != 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    return false;
}

int main(){

    string a, b, my_string = "";
    cin >> a >> b;

    int n = a.size(), m = b.size();

    int k = (n + m - 1) / n;
    my_string.reserve((k + 2) * n);

    for(int i = 0; i < k; i++){
        my_string += a;
    }

    if(kmp(my_string, b)){
        cout << k;
        return 0;
    }

    my_string += a;
    if(kmp(my_string, b)){
        cout << k + 1;
        return 0;
    }
    
    cout << -1;

    return 0;
}