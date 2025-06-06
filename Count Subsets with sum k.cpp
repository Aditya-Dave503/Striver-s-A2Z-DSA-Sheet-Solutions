#include<bits/stdc++.h>

int f(int ind,int s,vector<int>&arr, vector<vector<int>>&dp){
	 if(s==0) return 1;
	 if(ind==0) return arr[0]==s;

	if(dp[ind][s]!=-1) return dp[ind][s];
	int notpick=f(ind-1,s,arr,dp);
	int pick=0;
	if(arr[ind]<=s) pick=f(ind-1,s-arr[ind],arr,dp);

	return dp[ind][s]=pick+notpick;
}





int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return f(n-1,k,arr,dp);
}
