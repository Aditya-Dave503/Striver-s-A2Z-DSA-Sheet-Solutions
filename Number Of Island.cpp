class Solution {
    private:
    void dfs(int i,int j, vector<vector<char>>&grid, vector<vector<bool>>&vis, int m, int n){
        vis[i][j]=1;

        if(i-1>=0 && vis[i-1][j]!=1 && grid[i-1][j]=='1') dfs(i-1,j,grid,vis,m,n);
        if(i+1<m && vis[i+1][j]!=1 && grid[i+1][j]=='1') dfs(i+1,j,grid,vis,m,n);
        if(j-1>=0 && vis[i][j-1]!=1 && grid[i][j-1]=='1') dfs(i,j-1,grid,vis,m,n);
        if(j+1<n && vis[i][j+1]!=1 && grid[i][j+1]=='1') dfs(i,j+1,grid,vis,m,n);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<bool>>vis(m,vector<bool>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid,vis,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};
