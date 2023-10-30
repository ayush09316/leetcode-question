class Solution {
public:
    vector<int>parent;
    int findParent(int x){
        if(parent[x]==-1) return x;
        return parent[x]= findParent(parent[x]);
    }
    void _union(int a,int b){
        int p_a= findParent(a);
        int p_b= findParent(b);
        if(p_a==p_b) return ;
        parent[p_a]= p_b;
        
    }
    int makeConnected(int n, vector<vector<int>>& connect) {
        int m= connect.size() , ans=0;
        if(n-1>m) return -1;
        
        parent.resize(n+1,-1);
       
        for(auto it : connect)   _union(it[0],it[1]);
        
        for(int i=0;i<n;i++){
            if(parent[i]==-1) ans++;
        }
        return ans-1;
    }
};