#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    unordered_map<int,int>mpp;
    mpp[0]++;
    int xori=0;
    int n=a.size();
    int ans=0;

    for(int i=0;i<n;i++){
        xori=xori^a[i];
        int need=xori^b;
        if(mpp[need]>0){
            ans+=mpp[need];
        }
        mpp[xori]++;
    }
    return ans;
}
