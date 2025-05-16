#include <bits/stdc++.h> 
int kthSmallest(vector<int>& v, int n, int k) {
	priority_queue<int,vector<int>,greater<int>>pq;
	for(auto it:v) pq.push(it);
	int ans=0;

	for(int i=0;i<k;i++){
		ans=pq.top();
		pq.pop();
	}
	return ans;
} 
