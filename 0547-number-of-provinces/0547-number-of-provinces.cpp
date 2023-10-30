class Solution {
public:
    vector<int>parent;
    int findParent(int x){
        if (parent[x]==-1) return x; 
        return parent[x]=findParent(parent[x]);
    }
    void _union(int a,int b){
        int p_a=findParent(a) , p_b=findParent(b);
        if(p_a==p_b) return; 
        parent[p_a]=p_b;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
 		parent.resize(n+1, -1);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j){
                    _union(i,j);
                }
            }
        }
        
        int c=0; 
        for(int i=0;i<n;i++){
            if(parent[i]==-1) c++; 
        }

        return c; 
    }
};