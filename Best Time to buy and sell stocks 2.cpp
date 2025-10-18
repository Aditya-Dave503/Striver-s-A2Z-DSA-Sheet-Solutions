class Solution {
public:

    int f(int ind, int c, vector<int>&values, int n, vector<vector<int>>&dp){
        if(ind==n) return 0;

        if(dp[ind][c]!=-1) return dp[ind][c];

        int profit=0;
        if(c){
            profit=max(-values[ind]+f(ind+1,0,values,n,dp),0+f(ind+1,1,values,n,dp));
        }
        else{
            profit=max(values[ind]+f(ind+1,1,values,n,dp),0+f(ind+1,0,values,n,dp));
        }
        return dp[ind][c]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,n,dp);
    }
};
