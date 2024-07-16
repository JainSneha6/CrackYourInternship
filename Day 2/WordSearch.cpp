class Solution {
public:
    bool solve(int i, int j, int n, int m, int ind, vector<vector<char>>& board, string word){
        if(ind>=word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[ind] || board[i][j]=='@'){
            return false;
        }

        char ch=board[i][j];
        board[i][j]='@';

        bool top=solve(i-1,j,n,m,ind+1,board,word);
        bool bottom=solve(i+1,j,n,m,ind+1,board,word);
        bool right=solve(i,j-1,n,m,ind+1,board,word);
        bool left=solve(i,j+1,n,m,ind+1,board,word);

        board[i][j]=ch;
        return top||bottom||left||right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int ind=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[ind]){
                    if(solve(i,j,n,m,ind,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
