class Solution {
public:
    
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0 , n=stones.size();
        for(int num:stones) sum+=num;
        vector<vector<int>>dp(n+1,vector<int>(sum/2+1,0));

        for(int wt= stones[0];wt<=sum/2;wt++){
            dp[0][wt]=stones[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum/2;j++){
                int pick=0;
                if(stones[i]<=j) pick=stones[i] + dp[i-1][j-stones[i]];
                int notPick= dp[i-1][j];
                dp[i][j]= max(pick,notPick);
            }
        }
        return sum - 2*dp[n-1][sum/2];
    }
};