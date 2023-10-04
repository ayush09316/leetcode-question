class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int>uset;
        int cnt=0; int longest=1;

        for(int i=0;i<nums.size();i++){
            uset.insert(nums[i]);
        }

        for(auto it:uset){
            if(uset.find(it-1)==uset.end()){
                cnt=1;
                int x=it;
                while(uset.find(x+1)!=uset.end()){
                    x+=1;
                    cnt++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};