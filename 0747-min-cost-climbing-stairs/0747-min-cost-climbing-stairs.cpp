
class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(1001,-1);
        int n= cost.size();
        dp[0]=cost[0];
        dp[1]=cost[1];
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i-1], dp[i-2]) + (i == n ? 0 : cost[i]);
        }
        return dp[n];
    }
};