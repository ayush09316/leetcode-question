class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int n = nums.size();
        vector<int> sums(k, 0);
        sums[0]++;
        int cnt = 0;
        int currSum = 0;
        for(int num :nums) {
            currSum = (currSum + num%k + k)%k;
            cnt += sums[currSum];
            sums[currSum]++;
        }
        return cnt;
    }
};