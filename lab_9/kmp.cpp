#include <iostream>
#include <vector>
using namespace std;

vector<int> compute_lps(const string &pattern){
    int m = pattern.size();
    vector<int> lps(m, 0);
    int j = 0, i = 1;

    while(i < pattern.size()){
        if(pattern[i] == pattern[j]){ // If characters match
            j++;  // Increase the match length
            lps[i] = j;  // Store the match length in the LPS array
            i++;  // Move to the next character in the pattern
        }
        else{ // Mismatch occurred
            if(j > 0){ // If we have already matched some characters
                j = lps[i - 1]; // Backtrack to the last known match length
            }
            else{ // No match at all
                lps[i] = 0; // No match length for this character
                i++; // Move to the next character
            }
        }
    }
    return lps; // Return the LPS array
}

vector<int> kmp(const string &text, const string &pattern){
    vector<int> lps = compute_lps(pattern); // Step 1: Preprocess the pattern to get the LPS array
    vector<int> result; // This will store the starting indices of the matches

    int i = 0, j = 0; // i is the text index, j is the pattern index
    int text_size = text.size(), pattern_size = pattern.size();

    while(i < text_size){
        if(text[i] == pattern[j]){ // Step 3: Match found at both text[i] and pattern[j]
            i++; // Move to the next character in the text
            j++; // Move to the next character in the pattern
        }

        // Step 4: If we have matched the entire pattern, we found a match
        if(j == pattern_size){
            result.push_back(i - pattern_size); // Store the start index of the match
            j = lps[j - 1]; // Use the LPS array to avoid re-checking characters in the pattern
        }
        // Step 5: If there's a mismatch, use the LPS array to skip characters
        else if(i < text_size && text[i] != pattern[j]){
            if(j != 0){ // we already have matches
                j = lps[j - 1]; // Skip the already matched part using the LPS array
            }
            else{ // we don't have any matches, yet, so j = 0 for now
                i++; // Move to the next character in the text
            }
        }
    }
    return result; // Return the list of match indices
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