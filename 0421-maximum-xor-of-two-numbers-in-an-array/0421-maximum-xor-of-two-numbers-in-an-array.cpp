class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0, mask = 0;
        unordered_set<int> st;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i); 
            // Assume ans has the current answer with the current bit position
            int temp = ans | (1 << i);
            for (auto num : nums) {
                int num_masked = num & mask; 
                if (st.find(temp ^ num_masked) != st.end()) {
                    ans = temp; 
                    break;
                }
                st.insert(num_masked);
            }
            st.clear(); // Clear the set for the next iteration.
        }
        return ans; 
    }
};