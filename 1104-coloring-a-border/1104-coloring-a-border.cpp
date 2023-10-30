class Solution {
public:
    bool dfsHelper(vector<vector<int>>&grid, int r, int c,int &componentColor ,int &color,vector<vector<bool> >& visited){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){
            return true; 
        }
        if(visited[r][c])  return false;
        
        if(grid[r][c] != componentColor){
            //checking is color is different after checking visited because we ourselves may have had changed the color
            return true;
        }
        visited[r][c] = true;
        bool u = dfsHelper(grid,r-1,c,componentColor,color,visited);
        bool f = dfsHelper(grid,r,c+1,componentColor,color,visited);
        bool d = dfsHelper(grid,r+1,c,componentColor,color,visited);
        bool b = dfsHelper(grid,r,c-1,componentColor,color,visited);
        if(u || f || d || b){
            // GETTING TRUE IMPLIES THAT CURRENT VERTEX IS ON BORDER
            grid[r][c] = color; // changing to required color
        }
        return false;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));

        dfsHelper(grid,row,col,grid[row][col],color,visited);

        return grid;
    }
};