class Solution {
public:
    int f(int cur, int prev, int tar, vector<vector<int>> &dp) {
    if (cur == tar) return 0;
    if (cur + prev > tar) return 2000;
    
    if (dp[cur][prev] != -1) return dp[cur][prev];

    int cp = 2 + f(2*cur, cur, tar, dp);
    int p = 1 + f(cur + prev, prev, tar, dp);

    return dp[cur][prev] = min(cp, p);
    }

    int minSteps(int n) {
        if (n == 1) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return f(2, 1, n, dp) + 2;
    }
};