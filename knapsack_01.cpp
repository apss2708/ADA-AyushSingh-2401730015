#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int knapsack(const vector<int>& wt, const vector<int>& val, int W) {
    // dp[w] = best value possible with capacity exactly up to w.
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < static_cast<int>(wt.size()); i++) {
        // Traverse backward so each item is used at most once.
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }

    return dp[W];
}

int main() {
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {1, 4, 5, 7};
    int W = 7;

    // Expected answer for this sample is 9.
    cout << knapsack(wt, val, W) << "\n";
    return 0;
}
