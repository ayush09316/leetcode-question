#define ll long long
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
       int n = nums.size();
        vector<int> count(32,0);
        for(int num : nums){
            for(int i=0;i<32;i++){
                if(num & (1 << i)) count[i]++;
            }
        }

        ll res = 0, mod = 1e9 + 7;
        for(int j = 0;j<k;j++){
            ll x = 0;
            for(int i=0;i<32;i++){
                if(count[i] > 0){
                    count[i]--;
                    x |= (1 << i);
                }
            }
            res += x*x;
            res %= mod;
        }
        return res;
    }
    
};