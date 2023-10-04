class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int firstXorSec = 0, mask = 1, first = 0;
        
        for (auto &num: nums) firstXorSec ^= num;
        // get rightmost set bit in above xor
        while (!(firstXorSec & mask)) mask <<= 1;
        
        for (auto &num: nums){
            if (num & mask) first ^= num;
        }
        
        return {first, firstXorSec ^ first};
    }
};