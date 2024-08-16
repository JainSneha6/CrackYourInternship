class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, queue<pair<int,pair<int,int>>>& q){
        int n = grid.size();
        int m = grid[0].size();
        int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        q.push({0,{i,j}});
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int row = i+dir[k][0];
            int col = j+dir[k][1];
            if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && grid[row][col]==1){
                dfs(row,col,grid,vis,q);
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue <pair<int,pair<int,int>>> q;
        bool found = false;

        for(int i=0;i<n;i++){
            if(found){
                break;
            }
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,vis,q);
                    found = true;
                    break;
                }
            }
        }

        int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
            
        while(!q.empty()){
            int steps = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = x+dir[k][0];
                int ny = y+dir[k][1];

                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                    if(grid[nx][ny]==1){
                        return steps;
                    }
                    q.push({steps+1,{nx,ny}});
                    vis[nx][ny]=1;
                }
            }
        }
        return -1;
    }
};
