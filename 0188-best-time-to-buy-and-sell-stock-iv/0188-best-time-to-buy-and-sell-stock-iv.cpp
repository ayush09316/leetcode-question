class Solution {
public:
    int solve(vector<int>& prices,int limit,int index,int buy,vector<vector<vector<int>>>&dp){
        if(limit==0) return 0;
        if(index==prices.size()) return 0;
        if(dp[index][buy][limit]!=-1) return dp[index][buy][limit];
        int profit=0;
        if(buy){
            int buyIt= solve(prices,limit,index+1,0,dp)-prices[index];
            int notBuy=solve(prices,limit,index+1,1,dp);
            profit=max(notBuy,buyIt);
        }else{
            int sellIt= solve(prices,limit-1,index+1,1,dp)+prices[index];
            int notSell=solve(prices,limit,index+1,0,dp);
            profit=max(notSell,sellIt);
        }
        return dp[index][buy][limit]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,k,0,1,dp);
    }
};