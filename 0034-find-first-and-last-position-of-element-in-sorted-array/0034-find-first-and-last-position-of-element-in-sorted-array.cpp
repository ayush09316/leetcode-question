class Solution {
public:
    int lower_bound(vector<int>& nums, int low, int high, int target){
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int start = lower_bound(nums, low, high, target);
        int end = lower_bound(nums, low, high, target + 1) - 1;

        if(start < nums.size() && nums[start] == target){
            return {start, end};
        }
        return {-1, -1};
    }
};