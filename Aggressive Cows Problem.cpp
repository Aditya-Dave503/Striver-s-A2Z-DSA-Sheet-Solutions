#include<bits/stdc++.h>

bool f(vector<int>&temp,int mid,int k){
    int cnt=1,last=temp[0];

    for(int i=1;i<temp.size();i++){
        int it=temp[i];
        if(it-last>=mid){
            last=it;
            cnt++;
        }
    }

    return cnt>=k;
}



int aggressiveCows(vector<int> &temp, int k)
{
    int n=temp.size();

    sort(temp.begin(),temp.end());

    int low=1,high=temp[n-1]-temp[0];
    int ans=0;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(f(temp,mid,k)){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}
