class Solution {
public:
int dp[501][501];
    int cal(int i , int j ,int x,vector<int>&arr){
        if(i>j) return 0;

        if(dp[i][j]!=-1)  return dp[i][j];
        int a ,b,c;
        a = min(arr[i+1]-arr[i] , x) + cal(i+2 , j , x,arr);
        b = min(arr[j]-arr[i] , x) + cal(i+1 , j-1 , x ,arr);
        c = min(arr[j]-arr[j-1] , x) + cal(i , j-2 , x,arr);

        return dp[i][j] = min({a,b,c});
    }

    int minOperations(string s1, string s2, int x) {
        int n = s1.length();
        vector<int> arr;
        for(int  i= 0 ;  i< n ; i++){
            if(s1[i]!=s2[i])  arr.push_back(i);
        }

        if(arr.size()%2 == 1)  return -1;
        memset(dp,-1 , sizeof(dp));
        
        return cal(0 , arr.size()-1 , x,arr);
        
    }
};