class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int ones = 0 , temp=(1<<i);
            for ( int num : nums){
                if(num & temp) ones++;
            }
            if(ones%3) ans|=temp;
        }
        return ans;
    }
};