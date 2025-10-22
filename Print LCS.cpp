#include<bits/stdc++.h>
string helper(int ind1,int ind2,string &s1, string &s2,vector<vector<string>>&dp){
	if(ind1<0 || ind2<0) return "";

	if(dp[ind1][ind2]!="A") return dp[ind1][ind2];

	if(s1[ind1]==s2[ind2]){
		return dp[ind1][ind2]=helper(ind1-1,ind2-1,s1,s2,dp)+string(1,s1[ind1]);
	}
	
	string temp1=helper(ind1-1,ind2,s1,s2,dp);
	string temp2=helper(ind1,ind2-1,s1,s2,dp);

	if(temp1.size()>temp2.size()) dp[ind1][ind2]=temp1;
	else dp[ind1][ind2]=temp2;
	return dp[ind1][ind2];
}

string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<string>>dp(n,vector<string>(m,"A"));
	return helper(n-1,m-1,s1,s2,dp);	
}
