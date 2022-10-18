int mod = 1e9 + 7;
class Solution
{
    int rec(int n, int prev, int roll, vector<int> &rollMax, vector<vector<vector<int>>> &dp)
    {
        if (n == 0)
            return 1;
        if (dp[n][prev][roll] != -1)
            return dp[n][prev][roll];
        int ans = 0;
        for (int i = 1; i <= 6; i++)
        {
            if (i == prev && roll == rollMax[i - 1])
                continue;
            if (i != prev)
                ans = (ans + rec(n - 1, i, 1, rollMax, dp)) % mod;
            if (i == prev)
                ans = (ans + rec(n - 1, i, roll + 1, rollMax, dp)) % mod;
        }
        return dp[n][prev][roll] = ans;
    }

public:
    int dieSimulator(int n, vector<int> &rollMax)
    {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(7, vector<int>(16, -1)));
        return rec(n, 0, 0, rollMax, dp);
    }
};