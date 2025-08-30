#include <bits/stdc++.h> 
int mod=(int)(1e9+7);


int helper(int sum,vector<int>&arr, vector<vector<int>>&dp,int ind){
    if(ind==0){
        if(arr[0]==0 && sum==0) return 2;
        if(sum==0 || arr[0]==sum) return 1;
        return 0;
    }

    if(dp[ind][sum]!=-1) return dp[ind][sum];

    int nottake=helper(sum,arr,dp,ind-1);
    int take=0;

    if(arr[ind]<=sum) take=helper(sum-arr[ind],arr,dp,ind-1);

    return dp[ind][sum]=(nottake+take)%mod;
}


int findways(vector<int>&arr, int target){
    int n=arr.size();

    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return (helper(target,arr,dp,n-1)%mod);
}


int countPartitions(int n, int d, vector<int> &arr) {
    int totsum=0;

    for(auto it:arr) totsum+=it;

    if(totsum-d <0 || (totsum-d)%2) return 0;
    return findways(arr,(totsum-d)/2);
}


