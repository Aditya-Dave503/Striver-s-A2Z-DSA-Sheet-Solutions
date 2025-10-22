class Solution {
    private:
    int helper(int ind, int buy,vector<int>&a, vector<vector<int>>&dp){
        if(ind>=a.size()) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy==1){
            return dp[ind][buy]=max(-a[ind]+helper(ind+1,0,a,dp),helper(ind+1,1,a,dp));
        }
        else{
            return dp[ind][buy]=max(a[ind]+helper(ind+2,1,a,dp),helper(ind+1,0,a,dp));
        }
    }
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    dp[ind][buy]=max(-a[ind]+dp[ind+1][0],dp[ind+1][1]);
                }
                else{
                    dp[ind][buy]=max(a[ind]+dp[ind+2][1],dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
