class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, ans = 0;
        for (int i=31; i>=0; i--){
            mask |= 1<<i;
            unordered_set<int> myset;
            for (int num: nums) myset.insert(mask & num);
            int temp = ans | (1<<i);
            for (int prefix: myset) {
                if (myset.find(temp ^ prefix) != myset.end()) {
                    ans = temp; break;
                }
            }
        }
        return ans;
    }
};