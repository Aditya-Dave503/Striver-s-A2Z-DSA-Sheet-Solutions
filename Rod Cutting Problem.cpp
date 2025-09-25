#include<bits/stdc++.h>
// int helper(int ind, int n, vector<vector<int>> &dp, vector<int>&price){
// 	if(ind==0){
// 		return n*price[0];
// 	}

// 	if(dp[ind][n]!=-1) return dp[ind][n];
// 	int nottake=0+helper(ind-1,n,dp,price);
// 	int take=INT_MIN;

// 	if(ind+1<=n) take=price[ind] + helper(ind,n-ind-1,dp,price);

// 	return dp[ind][n]=max(take,nottake);
// }

int cutRod(vector<int> &price, int n)
{
	// vector<vector<int>>dp(n,vector<int>(n+1,-1));
	vector<int>prev(n+1,0),curr(n+1,0);

	for(int i=0;i<=n;i++) prev[i]=i*price[0];

	for(int i=1;i<n;i++){
		for(int j=0;j<=n;j++){
			int nottake=prev[j];
			int take=INT_MIN;

			if(i+1<=j) take=price[i]+prev[j-i-1];
			prev[j]=max(take,nottake);
		}
	}
	return prev[n];
}
