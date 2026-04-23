#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs(const string& a, const string& b) {
    int n = static_cast<int>(a.size());
    int m = static_cast<int>(b.size());
    // dp[i][j] stores LCS length for a[0..i-1] and b[0..j-1].
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // Matching characters extend the previous diagonal subsequence.
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // Otherwise, keep the best result after skipping one char.
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    cout << lcs("AGGTAB", "GXTXAYB") << "\n";
    return 0;
}
