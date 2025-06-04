class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>dp(n);

        for(int j=0;j<n;j++){
            dp[j]=triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            vector<int>temp(n,0);
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[j];
                int diag=triangle[i][j]+dp[j+1];
                temp[j]=min(diag,down);
            }
            dp=temp;
        }

        return dp[0];
    }
};
