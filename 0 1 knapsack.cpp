class Solution {
//   private:
//     int helper(int ind, int w, vector<int>&val, vector<int>&wt, vector<vector
//     <int>>&dp){
//         if(ind==0){
//             if(wt[0]<=w) return val[0];
//             return 0;
//         }
        
//         if(dp[ind][w]!=-1) return dp[ind][w];
        
//         int nottake=0,take=0;
//         nottake=helper(ind-1,w,val,wt,dp);
        
//         if(wt[ind]<=w) take=val[ind]+helper(ind-1,w-wt[ind],val,wt,dp);
        
//         return dp[ind][w]=max(take,nottake);
//     }
    
    
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        
        // vector<vector<int>>dp(n,vector<int>(W+1,0));
        
        vector<int>curr(W+1,0);
        
        for(int i=wt[0];i<=W;i++){
            curr[i]=val[0];
        }
        
        for(int i=1;i<n;i++){
            for(int j=W;j>=0;j--){
                int nottake=0,take=0;
                nottake=curr[j];
                if(wt[i]<=j) take=val[i]+curr[j-wt[i]];
                
                curr[j]=max(take,nottake);
            }
            // prev=curr;
        }
        return curr[W];
    }
};
