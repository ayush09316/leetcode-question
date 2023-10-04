class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans=0 ,n=nums.size() ,j=0,prev=0;

        for(int i=0;i<n;i++){
            if(nums[i]>=left && nums[i]<=right){
                ans+= i-j+1;
                prev=i-j+1;
            }
            else if(nums[i]<left){
                ans+=prev;
            }
            else {
                j=i+1;
                prev=0;
            }
        }
        return ans;
    }

};