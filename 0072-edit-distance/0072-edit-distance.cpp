class Solution {
public:

    int solve(string w1, string w2,int i,int j,vector<vector<int>>&dp){
        if(i==w1.length()) return w2.length()-j;
        if(j==w2.length()) return w1.length()-i;

        if(dp[i][j]!=-1) return dp[i][j];
         if(w1[i]==w2[j]) 
         return solve(w1,w2,i+1,j+1,dp);

         else{
              int insert= 1+solve(w1,w2,i,j+1,dp);
              int del= 1+solve(w1,w2,i+1,j,dp);
              int replace =1+solve(w1,w2,i+1,j+1,dp);
              return   dp[i][j]= min(insert,min(del,replace));
         }
         

    }
    int solveTab(string &a,string &b){
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));

        //step2 : analyse base case
        for(int j=0;j<=b.length();j++){
            dp[a.length()][j] = b.length()-j;
        }
        for(int i=0;i<=a.length();i++){
            dp[i][b.length()] = a.length()-i;
        }

        //step 3: Using Bottom Up Approach Calculate answer using Loops
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j])  ans = dp[i+1][j+1];
                else{
                    int insert = dp[i][j+1];
                    int deleteAns = dp[i+1][j];
                    int replace = dp[i+1][j+1];
                    ans = 1 + min(insert,min(deleteAns,replace));
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    int solveTabSO(string &a,string &b){
        //step1 : create dp array
        // vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        vector<int>curr(b.length()+1,0);
        vector<int>next(b.length()+1,0);
        //step2 : analyse base case
        //TODO
        for(int j=0;j<=b.length();j++){
            next[j] = b.length()-j;
        }

        //step 3: Using Bottom Up Approach Calculate answer using Loops
        for(int i=a.length()-1;i>=0;i--)
        {
            curr[b.length()] = a.length()-i;
            for(int j=b.length()-1;j>=0;j--)
            {
                int ans = 0;
                if(a[i] == b[j]){
                    ans = next[j+1];
                }
                else{
                    //insert 
                    int insert = curr[j+1];
                    //delete
                    int deleteAns = next[j];
                    //replace
                    int replace= next[j+1];
                    ans = 1 + min(insert,min(deleteAns,replace));
                }
                curr[j]=ans;
            }
            next = curr;
        }
        return next[0];
    }
    int minDistance(string a, string b) {
        //return solve(word1,word2,0,0,dp);
        return solveTab(a,b);
    }
};