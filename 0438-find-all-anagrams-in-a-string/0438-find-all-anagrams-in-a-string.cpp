class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> goal(26), cur(26), res;
        int n=s.size() , m=p.size();

        for(char ch : p) goal[ch - 'a']++;

        for(int i = 0; i < n; i++) {

            cur[s[i] - 'a']++;
            if(i >= m) cur[s[i - m] - 'a']--;
            if(cur == goal) res.push_back(i - m + 1);

        }
        
        return res;
    }
};