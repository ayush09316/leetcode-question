class Solution {
public:
    int solve(vector<int>& prices,int limit,int ind,int buy,vector<vector<vector<int>>>&dp){
        if(limit==0 || ind==prices.size()) return 0;
        
        if(dp[ind][buy][limit]!=-1) return dp[ind][buy][limit];
        
        int profit=0;
        if(buy){
            int buyIt= solve(prices,limit,ind+1,0,dp)-prices[ind];
            int notBuy=solve(prices,limit,ind+1,1,dp);
            profit=max(notBuy,buyIt);
        }else{
            int sellIt= solve(prices,limit-1,ind+1,1,dp)+prices[ind];
            int notSell=solve(prices,limit,ind+1,0,dp);
            profit=max(notSell,sellIt);
        }
        return dp[ind][buy][limit]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,2,0,1,dp);
    }
};