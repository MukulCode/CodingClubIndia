class Solution {
public:
    int dp[305][15];
    int find(vector<int> &diff, int d, int i) {
        if(d == 1) {
            if(i == diff.size()) {
                return INT_MAX / 4;
            }
            int mx = -1;
            for(int j = i; j < diff.size(); j++) {
                mx = max(diff[j], mx);
            }
            
            return mx;
        }
        if(dp[i][d] != -1) {
            return dp[i][d];
        }
        int mx = -1;
        int ans = INT_MAX / 2;
        for(int j = i; j < diff.size() - d + 1; j++) {
            mx = max(diff[j], mx);
            
            ans = min(ans, mx + find(diff, d - 1, j + 1));
        }
        return dp[i][d] =  ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp, -1, sizeof dp);
        int ans =  find(jobDifficulty, d, 0);
        return (ans >= INT_MAX / 2 ? -1 : ans);
    }
};