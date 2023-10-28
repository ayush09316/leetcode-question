class Solution {
public:
    int dp[367];
    int helper(int i, vector<int> &day, vector<int> &cost){
        if(i>=day.size()) return 0;
        
        if(dp[i]!=-1)  return dp[i];
        
        int pass1=upper_bound(day.begin(),day.end(),day[i]+1-1)-day.begin();
        int c1=helper(pass1,day,cost)+cost[0];

        int pass7=upper_bound(day.begin(),day.end(),day[i]+7-1)-day.begin();
        int c7=helper(pass7,day,cost)+cost[1];

        int pass3=upper_bound(day.begin(),day.end(),day[i]+30-1)-day.begin();
        int c3=helper(pass3,day,cost)+cost[2];
        
        return dp[i]=min({c1,c7,c3});
    } 
    int mincostTickets(vector<int>& days, vector<int>& costs) {        
        memset(dp,-1,sizeof(dp));
        return helper(0,days,costs);    
    }
};