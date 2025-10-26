class Solution {
    private:
    void dfs(int row,int col, vector<vector<bool>>&vis, vector<vector<char>>&board, int delrow[],int delcol[]){
        vis[row][col]=1;
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && board[nrow][ncol]=='O') dfs(nrow,ncol,vis,board,delrow,delcol);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<bool>>vis(m,vector<bool>(n,0));

        for(int i=0;i<n;i++){
            if(!vis[0][i] && board[0][i]=='O') dfs(0,i,vis,board,delrow,delcol);
            if(!vis[m-1][i] && board[m-1][i]=='O') dfs(m-1,i,vis,board,delrow,delcol);
        }

        for(int j=0;j<m;j++){
            if(!vis[j][0] && board[j][0]=='O') dfs(j,0,vis,board,delrow,delcol);
            if(!vis[j][n-1] && board[j][n-1]=='O') dfs(j,n-1,vis,board,delrow,delcol);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};
