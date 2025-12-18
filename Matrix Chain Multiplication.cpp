#include <bits/stdc++.h> 
int helper(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
    if(i==j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    long long int mini=1e9;

    for(int k=i;k<j;k++){
        long long cost=arr[i-1]*arr[k]*arr[j]+helper(i,k,arr,dp)+helper(k+1,j,arr,dp);
        mini=min(mini,cost);
    }
    return dp[i][j]=mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
    return helper(1,N-1,arr,dp);
}
