class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int ncolor){
        int n = image.size();
        int m = image[0].size();
        int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        for(int k=0;k<4;k++){
            int nsr = sr+dir[k][0];
            int nsc = sc+dir[k][1];
            if(nsr>=0 && nsr<n && nsc>=0 && nsc<m && image[nsr][nsc]==ncolor){
                image[nsr][nsc]=color;
                dfs(image,nsr,nsc,color,ncolor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ncolor = image[sr][sc];
        if(image[sr][sc]!=color){
            image[sr][sc]=color;
            dfs(image,sr,sc,color,ncolor);
        }
        return image;
    }
};
