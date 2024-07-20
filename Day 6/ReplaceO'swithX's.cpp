void dfs(vector<vector<char>>& mat, vector<vector<int>>& vis, int i, int j){
        vis[i][j]=1;
        int n=mat.size();
        int m=mat[0].size();
        int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
        for(int k=0;k<4;k++){
            int nrow = i + dir[k][0];
            int ncol = j + dir[k][1];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(mat,vis,nrow,ncol);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector <vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(mat,vis,i,0);
            }
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(mat,vis,i,m-1);
            }
        }
        
        for(int j=0;j<m;j++){
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(mat,vis,0,j);
            }
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(mat,vis,n-1,j);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
