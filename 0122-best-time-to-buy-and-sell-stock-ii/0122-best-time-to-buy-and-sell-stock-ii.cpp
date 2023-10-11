class Solution {
public:
    int find(int ind,vector<int> &v,bool buy,vector<vector<int>> &memo){
        if(ind>=v.size()) return 0;
        if(memo[ind][buy]!=-1) return memo[ind][buy];
        if(buy){
            int notTake=find(ind+1,v,buy,memo);
            int take=find(ind+1,v,!buy,memo)-v[ind];

            return memo[ind][buy]=max(take,notTake);  
        }else{
            int notSell=find(ind+1,v,buy,memo);
            int Sell=v[ind]+find(ind+1,v,!buy,memo);

            return memo[ind][buy]=max(Sell,notSell);  
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        vector<vector<int>> v(n+1,vector<int>(2,-1));
        return find(0,prices,1,v); 
    }
};