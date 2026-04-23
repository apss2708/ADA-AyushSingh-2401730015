#include <iostream>
#include <string>

using namespace std;

void naiveStringMatch(const string& text, const string& pattern) {
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());
    bool found = false;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Pattern not found\n";
    }
}

int main() {
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    naiveStringMatch(text, pattern);
    return 0;
}
