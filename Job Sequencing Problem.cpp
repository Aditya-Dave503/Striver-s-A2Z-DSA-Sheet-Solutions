#include<bits/stdc++.h>
static bool comp(vector<int>&v1,vector<int>&v2){
    return v1[2]>v2[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(),jobs.end(),comp);
    int totprofit=0,cnt=0,maxdeadline=-1;
    int n=jobs.size();

    for(int i=0;i<n;i++) maxdeadline=max(maxdeadline,jobs[i][1]);

    vector<int>hash(maxdeadline+1,-1);

    for(int i=0;i<n;i++){
        for(int j=jobs[i][1];j>=1;j--){
            if(hash[j]==-1){
                cnt++;
                hash[j]=jobs[i][0];
                totprofit+=jobs[i][2];
                break;
            }
        }
    }

    return {cnt,totprofit};
}
