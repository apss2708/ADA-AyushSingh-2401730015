def knapsack(wt, val, W):
    dp = [0] * (W + 1)
    for i in range(len(wt)):
        for w in range(W, wt[i] - 1, -1):
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i])
    return dp[W]

wt = [1, 3, 4, 5]
val = [1, 4, 5, 7]
W = 7
print(knapsack(wt, val, W))