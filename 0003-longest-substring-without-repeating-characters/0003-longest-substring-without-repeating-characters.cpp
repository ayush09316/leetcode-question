class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;int right=0; 
        int longest=0;
        vector<int>v(256,-1);

        while(right<s.length()){
            if(v[s[right]]!=-1) left=max(left,v[s[right]]+1);
            v[s[right]]=right;
            longest=max(longest,right-left+1);
            right++;
        }
        return longest;
    }
}; 