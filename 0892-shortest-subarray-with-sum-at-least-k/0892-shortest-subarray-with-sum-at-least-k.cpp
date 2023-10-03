class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long pref[n + 1];
        
        pref[0] = 0;
        for(int i = 1; i != n + 1; ++i)
            pref[i] = pref[i - 1] + nums[i - 1];
        
        deque<int> dq;
        int res = INT_MAX;
        
        dq.push_back(0);
        for(int i = 1; i != n + 1; ++i) {
            while(!dq.empty() && pref[dq.back()] >= pref[i])
                dq.pop_back();
            while(!dq.empty() && pref[i] - pref[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }
        return res == INT_MAX ? -1 : res;

    }
};