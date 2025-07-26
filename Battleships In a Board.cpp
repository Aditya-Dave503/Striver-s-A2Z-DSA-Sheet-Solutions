class Solution {
    private:
    void dfs(int i,int j, vector<vector<char>>& board,int m,int n, int start, int end){
        board[i][j]='.';

        if(i-1>=0 && (start==i-1 || end==j) && board[i-1][j]=='X') dfs(i-1,j,board,m,n,start,end);
        if(i+1<m && (start==i+1 || end==j) && board[i+1][j]=='X')  dfs(i+1,j,board,m,n,start,end);
        if(j-1>=0 && (start==i || end==j-1) && board[i][j-1]=='X') dfs(i,j-1,board,m,n,start,end);
        if(j+1<n && (start==i || end==j+1) && board[i][j+1]=='X') dfs(i,j+1,board,m,n,start,end);
    }

public:
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    dfs(i,j,board,m,n,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
