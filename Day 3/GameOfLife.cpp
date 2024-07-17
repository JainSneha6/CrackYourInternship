class Solution {
private:
    int countLive(vector<vector<int>>& board, int x, int y, int n, int m){
        int count=0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(i==0 && j==0){
                    continue;
                }
                int nx = x+i;
                int ny = y+j;
                if(nx>=0 && ny>=0 && nx<n && ny<m && (board[nx][ny]==1||board[nx][ny]==2)){
                    count++;
                }
            }
        }
        return count;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=countLive(board,i,j,n,m);
                if(board[i][j]==1 && (count<2||count>3)){
                    board[i][j]=2;
                }
                else if(board[i][j]==0 && count==3){
                    board[i][j]=3;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2){
                    board[i][j]=0;
                }
                else if(board[i][j]==3){
                    board[i][j]=1;
                }
            }
        }
    }
};
