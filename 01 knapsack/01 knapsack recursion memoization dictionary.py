def knapSack(self,W, wt, val, n):
    def knapsack(W, wt, val, n, memo = {}):
        if (n, W) in memo:
            return memo[(n, W)]

        if n == 0 or W == 0:
            return 0

        elif wt[n - 1] <= W:
            memo[(n, W)] = max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1, memo), knapsack(W, wt, val, n - 1, memo))
            return memo[(n, W)]

        else:
            memo[(n, W)] = knapsack(W, wt, val, n - 1, memo)
            return memo[(n, W)] 

    return knapsack(W, wt, val, n)

N = 3
W = 3
values = [1,2,3]
weight = [4,5,6]
print(knapSack(W, weight, values, N))