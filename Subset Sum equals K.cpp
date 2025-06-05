#include <bits/stdc++.h> 

bool f(int n, int k, vector<int>&arr, vector<vector<int>>&dp){
    if(k==0) return true;

    if(n==0) return (arr[0]==k);

    if(dp[n][k] != -1) return dp[n][k];

    bool nottake = f(n-1,k,arr,dp);

    bool take=0;
    if(k>=arr[n]){
        take = f(n-1, k-arr[n], arr, dp);
    }

    return dp[n][k]=(take || nottake);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));

    return f(n-1, k, arr, dp);
}
