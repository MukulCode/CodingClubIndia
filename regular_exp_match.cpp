class Solution
{
    bool rec(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (j < 0 && i < 0)
            return true;
        if (j < 0)
            return false;
        if (i < 0)
        {
            while (j >= 0)
            {
                if (t[j] != '*')
                    return false;
                j -= 2;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        bool ans;
        if (s[i] == t[j] || t[j] == '.')
            ans = rec(i - 1, j - 1, s, t, dp);
        else if (t[j] == '*')
        {
            if (t[j - 1] != s[i] && t[j - 1] != '.')
                ans = rec(i, j - 2, s, t, dp);
            else
            {
                ans = rec(i - 1, j, s, t, dp) || rec(i, j - 2, s, t, dp);
            }
        }
        else
            ans = false;
        return dp[i][j] = ans;
    }

public:
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(n - 1, m - 1, s, p, dp);
    }
};