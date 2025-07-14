class Solution {
public:

    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image, int ini,int delrow[],int delcol[],int color){
        ans[sr][sc]=color;

        int n=image.size();
        int m=image[0].size();

        for(int i=0;i<4;i++){
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==ini && ans[nrow][ncol]!=color){
                dfs(nrow,ncol,ans,image,ini,delrow,delcol,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini=image[sr][sc];
        if(ini==color) return image;
        vector<vector<int>>ans=image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr,sc,ans,image,ini,delrow,delcol,color);
        return ans;
    }
};
