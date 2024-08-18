class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue <pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }

        if(q.empty() || q.size()==n*n){
            return -1;
        }

        int max_dist = -1;
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int nx = x + dir[k][0];
                int ny = y + dir[k][1];
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                    grid[nx][ny]=grid[x][y]+1;
                    max_dist = max(max_dist,grid[nx][ny]-1);
                    q.push({nx,ny});
                }
            }
        }
        return max_dist;
    }
};
