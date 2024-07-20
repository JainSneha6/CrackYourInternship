class Solution {
  public:
    void dfs(vector<vector<char>>& grid, vector <vector<int>>& vis, int i, int j){
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int row=-1;row<=1;row++){
            for(int col=-1;col<=1;col++){
                int nrow=i+row;
                int ncol=j+col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                    dfs(grid,vis,nrow,ncol);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};
