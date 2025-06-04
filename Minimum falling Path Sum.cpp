class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        vector<int>dp(n,0);

        for(int i=0;i<n;i++) dp[i]=matrix[0][i];

        for(int i=1;i<n;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                int up=dp[j]+matrix[i][j];
                int rightdiag=(j<n-1)?dp[j+1]+matrix[i][j]:1e9;
                int leftdiag=(j>0)?dp[j-1]+matrix[i][j]:1e9;
                temp[j]=min({up,leftdiag,rightdiag});
            }
            dp=temp;
        }
        return *min_element(dp.begin(),dp.end());
    }
};
