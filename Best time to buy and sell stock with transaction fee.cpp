class Solution {
public:
    int helper(int ind, int buy, vector<int>&a, int fee, vector<vector<int>>&dp){
        if(ind==a.size()) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy){
            return dp[ind][buy]=max(-a[ind]+helper(ind+1,0,a,fee,dp),helper(ind+1,1,a,fee,dp));
        }
        else{
            return dp[ind][buy]=max(a[ind]-fee+helper(ind+1,1,a,fee,dp),helper(ind+1,0,a,fee,dp));
        }
    }
    int maxProfit(vector<int>&a, int fee) {
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[ind][buy]=max(-a[ind]+dp[ind+1][0],dp[ind+1][1]);
                }
                else{
                    dp[ind][buy]=max(a[ind]-fee+dp[ind+1][1],dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
