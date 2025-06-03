class Solution {
public:

long long int f(int m,int n,vector<vector<long long int>>&dp){
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;

    if(dp[m][n]!=-1) return dp[m][n];
    long long int up=f(m-1,n,dp);
    long long int left=f(m,n-1,dp);
    return dp[m][n]=up+left;
}


    long long int uniquePaths(int m, int n) {
        vector<vector<long long int>>dp(m,vector<long long int>(n,-1));
        return f(m-1,n-1,dp);
    }
};
