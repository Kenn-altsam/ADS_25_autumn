#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compute_lps(const string &text, const string &pattern){
    int m = pattern.size();
    vector<int> lps(m, 0);
    int i = 1, j = 0;
    
    while(i < m){
        if(pattern[i] == text[j]){
            lps[i] = j + 1;
            j++;
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
    int result = lps[m - 1];
    return result;
}

// vector<int> kmp(const string &text, const string &pattern){
//     int text_size = text.size(), pattern_size = pattern.size();
    
//     vector<int> result;
//     int i = 0, j = 0;

//     while(i < text_size){
//         if(text[i] == pattern[j]){
//             i++;
//             j++;
//         }

//         if(j == pattern_size){
//             result.push_back(j - pattern_size);
//             j = lps[j - 1];
//         }
//         else if(i < text_size && text[i] != pattern[j]){
//             if(j != 0){
//                 j = lps[j - 1];
//             }
//             else{
//                 i++;
//             }
//         }
//     }
//     return result;
// }

int main(){

    string my_string;
    cin >> my_string;

    my_string[0] = tolower(my_string[0]);

    int n;
    cin >> n;
    
    int max_lps = -1;
    vector<string> max_lps_strings;

    for(int i = 0; i < n; i++){
        string current;
        cin >> current;

        string modified = current;
        modified[0] = tolower(current[0]);

        int length = compute_lps(modified, my_string);

        if(length > max_lps){
            max_lps = length;
            max_lps_strings.clear();
            max_lps_strings.push_back(current);
        }
        else if(length == max_lps){
            max_lps_strings.push_back(current);
        }
    }

    if(max_lps == 0){
        cout << 0;
    }
    else{
        cout << max_lps_strings.size() << endl;
        vector<string>::iterator it;
        for(it = max_lps_strings.begin(); it != max_lps_strings.end(); it++){
            cout << *it << endl;
        }
    }

    return 0;
}