class Solution {
private:
    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(int k=0;k<4;k++){
            int nrow = row+dir[k][0];
            int ncol = col+dir[k][1];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                vis[nrow][ncol]=1;
                dfs(grid,nrow,ncol,vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int num = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j,vis);
                    num++;
                }
            }
        }
        return num;
    }
};
