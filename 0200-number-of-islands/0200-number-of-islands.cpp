class Solution {
public:
    bool isValid(int i,int j,int n, int m,vector<vector<char>>& grid){
        if(i<n && j<m && i>=0 && j>=0 && grid[i][j]=='1'){
            return true;
        }
        return false;
    }
    void numIslandRec(int i,int j,int n, int m,vector<vector<char>>& grid){
        grid[i][j]='0';
        if(isValid(i+1,j,n,m,grid))  numIslandRec(i+1,j,n,m,grid);
        if(isValid(i-1,j,n,m,grid))  numIslandRec(i-1,j,n,m,grid);
        if(isValid(i,j+1,n,m,grid))  numIslandRec(i,j+1,n,m,grid);
        if(isValid(i,j-1,n,m,grid))  numIslandRec(i,j-1,n,m,grid);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m =grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    numIslandRec(i,j,n,m,grid);
                }

            }
        }
        return ans;
    }
};