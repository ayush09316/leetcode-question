class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size(), i=0;
        while(i<n){
            if(nums[i]==i+1){
                i++;
                continue;
            }
            else if(nums[i]<=0 || nums[i]>n){
                i++;
                continue;
            }
    
            int ind1=i , ind2 = nums[i]-1;

            if(nums[ind1]==nums[ind2]){
                i++;
                continue;
            }

            swap(nums[ind1],nums[ind2]);
    }

        for(int j=0;j<n;j++){
            if(nums[j]!=j+1) return j+1;
        }
        return n+1;

    }
};