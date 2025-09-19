// Recursive DP
#include<bits/stdc++.h>

int helper(int ind, int n, int w, vector<int>&profit, vector<int>&weight,
vector<vector<int>>&dp){
    if(ind==0){
        if(weight[ind]<=w) return (w/weight[0])*(profit[0]);
        return 0;
    }

    if(dp[ind][w]!=-1) return dp[ind][w];
    
    int nottake=0+helper(ind-1,n,w,profit,weight,dp);
    int take=0;
    if(weight[ind]<=w) take=profit[ind]+helper(ind,n,w-weight[ind],profit,weight,dp);

    return dp[ind][w]=max(take, nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return helper(n-1,n,w,profit,weight,dp);
}

// Memoization+tabulation

#include<bits/stdc++.h>

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>>dp(n,vector<int>(w+1,0));

    for(int i=weight[0];i<=w;i++) dp[0][i]=(i/weight[0])*(profit[0]);

    for(int i=1;i<n;i++){
        for(int W=0;W<=w;W++){
            int nottake=dp[i-1][W];
            int take=0;
            if(weight[i]<=W) take=profit[i]+dp[i][W-weight[i]];
            dp[i][W]=max(take,nottake);
        }
    }
    return dp[n-1][w];
}


// Space Optimization O(n*w) --> O(2*w)

#include<bits/stdc++.h>

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int>prev(w+1,0),curr(w+1,0);

    for(int i=weight[0];i<=w;i++) prev[i]=(i/weight[0])*(profit[0]);

    for(int i=1;i<n;i++){
        for(int W=0;W<=w;W++){
            int nottake=prev[W];
            int take=0;
            if(weight[i]<=W) take=profit[i]+curr[W-weight[i]];
            curr[W]=max(take,nottake);
        }
        prev=curr;
    }
    return prev[w];
}

// More space optimization O(w)

#include<bits/stdc++.h>

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int>prev(w+1,0);

    for(int i=weight[0];i<=w;i++) prev[i]=(i/weight[0])*(profit[0]);

    for(int i=1;i<n;i++){
        for(int W=0;W<=w;W++){
            int nottake=prev[W];
            int take=0;
            if(weight[i]<=W) take=profit[i]+prev[W-weight[i]];
            prev[W]=max(take,nottake);
        }
    }
    return prev[w];
}
