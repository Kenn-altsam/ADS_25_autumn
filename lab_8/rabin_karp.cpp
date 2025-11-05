#include <iostream>
#include <vector>

using namespace std;

// Compute hash of entire string
int get_hash(string s) {
    int p = 29;
    int p_pow = 1;  // p^0
    int h = 0;

    for (int i = 0; i < s.size(); i++) {
        h += s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}

// Compute prefix hash array
vector<int> get_h(string s) {
    int n = s.size();
    vector<int> h(n);

    h[0] = s[0];
    int p = 29;
    int p_pow = 29;  // p^1

    for (int i = 1; i < n; i++) {
        h[i] = h[i - 1] + s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // Precompute powers of p
    vector<int> p(s1.size());
    p[0] = 1;
    for (int i = 1; i < s1.size(); i++)
        p[i] = p[i - 1] * 29;

    // Hash of pattern
    int h_s2 = get_hash(s2);

    // Prefix hashes of text
    vector<int> h = get_h(s1);

    int n = s1.size();
    int m = s2.size();

    // Find all occurrences
    for (int i = 0; i < n - m + 1; i++) {
        int j = i + m - 1;  // End of current window

        // Get hash of substring s1[i...j]
        int hash = h[j];
        if (i > 0)
            hash = hash - h[i - 1];

        // Compare with pattern hash
        // hash = actual_hash × p^i, so compare with h_s2 × p^i
        if (hash == h_s2 * p[i])
            cout << i << " ";
    }

    return 0;
}