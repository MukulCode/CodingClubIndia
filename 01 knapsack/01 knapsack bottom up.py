def knapsack(W, wt, val, n):

    dp = [[-1 for x in range(W + 1)] for y in range(n + 1)]
    for x in range(n + 1):
        for y in range(W + 1):
            if x == 0 or y == 0:
                dp[x][y] = 0

    for x in range(1, n + 1):
        for y in range(1, W + 1):
            if wt[x - 1] <= y:
                dp[x][y] = max(val[x - 1] + dp[x - 1][y - wt[x - 1]], dp[x - 1][y])
            else:
                dp[x][y] = dp[x - 1][y]
    return dp[-1][-1]

n = 3
W = 4
wt = [4, 5, 1]
val = [1, 2, 3]
print(knapsack(W, wt, val, n))