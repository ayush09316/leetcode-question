class Solution {
public:
    unordered_map<int, int> mp;
    int dp[2000][2000];
    int solve(int curr_stone_idx, int prevJump, vector<int>& stones) {
        if (curr_stone_idx == stones.size() - 1)  return true;
        
        if (dp[curr_stone_idx][prevJump] != -1){
            return dp[curr_stone_idx][prevJump] ;
        }
        
        bool ans = false;
        
        for(int next_jump = prevJump-1; next_jump <= prevJump+1; next_jump++){
            if(next_jump>0){

                int next_stone = stones[curr_stone_idx] + next_jump;

                if(mp.find(next_stone)!=mp.end()){
                    ans = ans || solve(mp[next_stone],next_jump,stones);
                }
            }
        }

        return dp[curr_stone_idx][prevJump] = ans;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]>1) return false;

        for (int i = 0; i < stones.size(); i++) mp[stones[i]] = i;
        
        memset(dp, -1, sizeof(dp));

        return solve(mp[0], 0, stones);
    }
};