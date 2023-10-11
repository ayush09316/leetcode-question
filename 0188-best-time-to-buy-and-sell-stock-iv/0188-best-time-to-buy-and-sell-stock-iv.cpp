class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> next(2, vector<int>(k + 1, 0)), 
        cur(2, vector<int>(k + 1, 0));

        for(int day = n - 1; day>=0; day--) {
            for(int canBuy = 0; canBuy<=1; canBuy++) {
                for(int cap = 1; cap<=k; cap++) {
                    int ans = 0;
                    if(canBuy) {
                        ans = max(-prices[day] + next[0][cap], next[1][cap]);
                    }
                    else {
                        ans = max(prices[day] + next[1][cap - 1], next[0][cap]);
                    }
                    cur[canBuy][cap] = ans;
                }
            }
            next = cur;
        }
        return next[1][k];
    }
};