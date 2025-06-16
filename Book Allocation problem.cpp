#include<bits/stdc++.h>

bool f(vector<int>&arr,int m,int mid){
    long long int sum=0;
    int ans=1;

    for(auto it:arr){
        if(it>mid) return 0;
        if(sum+it>mid){
            sum=it;
            ans+=1;
        }
        else sum+=it;
    }
    return ans<=m;
}


int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.

    if(m>n) return -1;

    long long int maxi=*max_element(arr.begin(),arr.end());
    long long int sum=0;

    for(int i=0;i<n;i++) sum+=arr[i];

    long long int low=maxi,high=sum,ans=-1;

    while(low<=high){
        long long int mid=low+(high-low)/2;

        if(f(arr,m,mid)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
