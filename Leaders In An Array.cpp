#include <bits/stdc++.h> 
vector<int> findLeaders(vector<int> &arr, int n) {
    // Write your code here.
    long long int maxi=INT_MIN;
    vector<int>ans;

    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            maxi=arr[i];
            ans.push_back(arr[i]);
        }
    }

    reverse(ans.begin(),ans.end());
    return ans;
}
