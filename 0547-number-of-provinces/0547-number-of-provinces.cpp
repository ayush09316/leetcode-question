class Solution {
public:
    vector<int>parent;
    int findParent(int x){
        return (parent[x]==x)? x: findParent(parent[x]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        int ans = n;
 		parent.resize(n+1, 0);
 		for (int i = 0; i <= n; i++)   parent[i] = i;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j] && i!=j){
                    int x= findParent(i+1);
                    int y= findParent(j+1);
                    if(x!=y){
                        parent[x]=y;
                        ans--;
                    }

                }
            }
        }
        return ans;
    }
};