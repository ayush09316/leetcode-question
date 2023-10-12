class Solution {
private:
    int n; int memo[2000];
    bool isPalindrome(string& s, int l, int r){
        while(l < r){
            if(s[l++] != s[r--])  return false;
        }
        return true;
    }
    int solve(string& s, int idx){
        if(idx >= n)  return 0;
        if(memo[idx] != -1) return memo[idx];
        
        int minSteps = INT_MAX;
        for(int k=idx; k<n; k++){
            if(isPalindrome(s, idx, k)){
                int steps = 1 + solve(s, k+1);
                minSteps = min(minSteps, steps);
            }
        }
        return memo[idx]=minSteps;
    }
public:
    int minCut(string s) {
        n = s.size();
        memset(memo, -1, sizeof(memo));
        return solve(s, 0) - 1;
    }
};