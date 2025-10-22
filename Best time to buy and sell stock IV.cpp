class Solution {
public:
    int helper(int ind, int tran,vector<int>&a,int n, int k,vector<vector<int>>&dp){
        if(ind==n || tran==2*k) return 0;

        if(dp[ind][tran]!=-1) return dp[ind][tran];

        if(tran%2==0){  // buy
            return dp[ind][tran]=max(-a[ind]+helper(ind+1,tran+1,a,n,k,dp),helper(ind+1,tran,a,n,k,dp));
        }
        else{
            return dp[ind][tran]=max(a[ind]+helper(ind+1,tran+1,a,n,k,dp),helper(ind+1,tran,a,n,k,dp));
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
        return helper(0,0,prices,n,k,dp);
    }
};
