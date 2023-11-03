class Solution {
public:
    bool solve(int mid,int th, vector<int>&nums){
        int sum=0;
       for(int num : nums){
        sum+= ceil((double)(num)/(double)(mid));
       }
       return sum<=th;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=1 , high=nums[n-1];
        while(low<high){
            int mid= low + (high-low)/2;
            if(solve(mid,threshold,nums)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};