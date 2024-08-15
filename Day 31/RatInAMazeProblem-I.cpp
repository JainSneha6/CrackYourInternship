class Solution {
  private:
    bool isSafe(int x, int y, int n, vector<vector<int>> &mat, vector<vector<int>> &vis){
        return (x>=0 && x<n && y>=0 && y<n && mat[x][y]==1 && !vis[x][y]);
    }
    
    void find(vector<vector<int>> &mat, int n, int x, int y, string path, vector<vector<int>>& vis, vector <string>& ans){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        vis[x][y]=1;
        
        if(isSafe(x+1,y,n,mat,vis)){
            path.push_back('D');
            find(mat,n,x+1,y,path,vis,ans);
            path.pop_back();
        }
        
        if(isSafe(x-1,y,n,mat,vis)){
            path.push_back('U');
            find(mat,n,x-1,y,path,vis,ans);
            path.pop_back();
        }
        
        if(isSafe(x,y+1,n,mat,vis)){
            path.push_back('R');
            find(mat,n,x,y+1,path,vis,ans);
            path.pop_back();
        }
        
        if(isSafe(x,y-1,n,mat,vis)){
            path.push_back('L');
            find(mat,n,x,y-1,path,vis,ans);
            path.pop_back();
        }
        
        vis[x][y]=0;
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        
        vector <string> ans;
        
        if(mat[0][0]==0){
            return ans;
        }
        
        vector <vector<int>> vis(n,vector<int>(n,0));
        
        find(mat,n,0,0,"",vis,ans);
        
        return ans;
    }
};
