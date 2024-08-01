public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector <vector<int>> vis(n,vector<int>(m,0));
        int fresh = 0;
        queue <pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        int time = 0;
        int count = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row+dir[i][0];
                int ncol = col+dir[i][1];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=1;
                    count++;
                    time = max(time, t + 1);
                }
            }
        }
        if(count!=fresh){
            return -1;
        }
        return time;
    }
