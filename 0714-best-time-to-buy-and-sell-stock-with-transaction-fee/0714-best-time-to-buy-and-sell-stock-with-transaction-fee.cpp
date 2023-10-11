class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       int currentBuy = INT_MIN;
        int currentSell = 0;
        for (int price : prices)
        {
            currentBuy = max(currentBuy, currentSell - price);
            currentSell = max(currentSell, currentBuy + price - fee);
        }

        return currentSell;
    }
};