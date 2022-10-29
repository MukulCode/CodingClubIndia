def knapSack(W, wt, val, n):
	if n == 0 or W == 0:
		return 0

	if wt[n - 1] <= W:
		return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), 
			knapSack(W, wt, val, n - 1))

	else:
		return knapSack(W, wt, val, n - 1)

n = 3
W = 4
wt = [4, 5, 1]
val = [1, 2, 3]
print(knapSack(W, wt, val, n))