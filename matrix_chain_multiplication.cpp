#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int mcm(const vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int length = 2; length < n; length++) {
        for (int i = 0; i + length < n; i++) {
            int j = i + length;
            dp[i][j] = numeric_limits<int>::max();

            for (int k = i + 1; k < j; k++) {
                long long cost = static_cast<long long>(dp[i][k]) + dp[k][j] +
                                 static_cast<long long>(arr[i]) * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], static_cast<int>(cost));
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    cout << mcm(arr) << "\n";
    return 0;
}
