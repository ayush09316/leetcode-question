class Solution {
public:
    bool isPalindrome(string& s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void solve(vector<vector<string>> &res, vector<string> &temp,string s,int start){
        if(start==s.size()){
            res.push_back(temp);
            return;
        }

        for(int j=start;j<s.size();j++){
            if(isPalindrome(s,start,j)){
                temp.push_back(s.substr(start,j-start+1));
                solve(res,temp,s,j+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        solve(res,temp,s,0);
        return res;
    }
};