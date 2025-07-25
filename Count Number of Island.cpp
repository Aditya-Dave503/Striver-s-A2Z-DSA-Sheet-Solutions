class Solution {
public:
    void dfs(int i,int j, vector<vector<int>>&grid, vector<vector<bool>>&vis,long long int &sum, int m, int n){
        vis[i][j]=1;
        sum+=grid[i][j];

        if(i+1<m && vis[i+1][j]==0 && grid[i+1][j]!=0){
            dfs(i+1,j,grid,vis,sum,m,n);
        }

        if(i-1>=0 && vis[i-1][j]==0 && grid[i-1][j]!=0){
            dfs(i-1,j,grid,vis,sum,m,n);
        }

        if(j+1<n && vis[i][j+1]==0 && grid[i][j+1]!=0){
            dfs(i,j+1,grid,vis,sum,m,n);
        }

        if(j-1>=0 && vis[i][j-1]==0 && grid[i][j-1]!=0){
            dfs(i,j-1,grid,vis,sum,m,n);
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,0));

        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]){
                    long long int sum=0;
                    dfs(i,j,grid,vis,sum,m,n);
                    if(sum%k==0) cnt++;
                }
            }
        }
        return cnt;
    }
};
