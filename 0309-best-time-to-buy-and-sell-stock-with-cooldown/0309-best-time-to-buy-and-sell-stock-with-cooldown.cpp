class Solution {
public:
    int solve(vector<int>& prices,int index,int buy,vector<vector<int>>&dp){
        if(index>=prices.size()) return 0;

        if(dp[index][buy]!=-1) return dp[index][buy];

        int profit=0;

        if(buy){
            int buyIt= solve(prices,index+1,0,dp)-prices[index];
            int notBuy=solve(prices,index+1,1,dp);
            profit=max(notBuy,buyIt);
        }else{
            int sellIt= solve(prices,index+2,1,dp)+prices[index];
            int notSell=solve(prices,index+1,0,dp);
            profit=max(notSell,sellIt);
        }

        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<vector<int>>dp(n,vector<int>(2,-1));
       return solve(prices,0,1,dp);

        
    }
};