class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int i, len=1, maxlen=1;
        for(i=1 ; i<nums.size() ; i++)
        {
            if(nums[i]>nums[i-1])  len++;
            
            else if(len>maxlen){
                maxlen = len;
                len=1;
            }
            else   len=1;
            
        }
        if(len>maxlen)  maxlen = len;
        return maxlen;
    }
};