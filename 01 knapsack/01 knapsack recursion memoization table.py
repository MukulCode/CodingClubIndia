def knapsack(W, wt, val, n, memo):
    if memo[n][W] != -1:
        return memo[n][W]

    if n == 0 or W == 0:
        return 0

    if wt[n - 1] <= W:
        temp = max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1, memo), 
            knapsack(W, wt, val, n - 1, memo))
        memo[n][W] = temp
        return temp

    else:
        temp = knapsack(W, wt, val, n - 1, memo)
        memo[n][W] = temp
        return temp

n = 3
W = 4
wt = [4, 5, 1]
val = [1, 2, 3]
memo = [[-1 for x in range(W + 1)] for y in range(n + 1)]
print(knapsack(W, wt, val, n, memo))