class Solution {
public:
     bool isMatch(string s, string p) {
       // return helper(s,p,0,0,dp);
       return tab(s,p);
    }

    bool tab(string s, string p){
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,0));
        dp[s.length()][p.length()]=1;
        
        for(int i=s.length();i>=0;i--)
        {
            for(int j=p.length()-1;j>=0;j--)
            {
                bool first_match=(i<s.length() && (p[j]==s[i]|| p[j]=='.'));
                    if(j+1<p.length() && p[j+1]=='*')
                    {
                        dp[i][j]=dp[i][j+2] || (first_match && dp[i+1][j]);
                    }
                else
                {
                    dp[i][j]=first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
    
    bool helper(string s, string p, int i, int j,vector<vector<int>> &dp){
        if(j==p.length())  return i==s.length();
        if(dp[i][j]>=0)    return dp[i][j];

        bool first_match=(i<s.length() && (s[i]==p[j] || p[j]=='.' ));
        bool ans=0;

        if(j+1<p.length() && p[j+1]=='*'){
            ans= (helper(s,p,i,j+2,dp)|| (first_match && helper(s,p,i+1,j,dp) ));
        }
        else{
            ans= (first_match && helper(s,p,i+1,j+1,dp));
        }
        return dp[i][j]=ans;
    }
};