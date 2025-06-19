#include<bits/stdc++.h>

int blackbox(vector<vector<int>> &matrix, int mid, int n, int m){
    int cnt=0;

    for(int i=0;i<n;i++){
        cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
    }
    return cnt;
}


int getMedian(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();

    int low=1e9,high=0;

    for(int i=0;i<n;i++){
        low=min(low,matrix[i][0]);
        high=max(high,matrix[i][m-1]);
    }

    int req=(n*m)/2;
    while(low<=high){
        int mid=low+(high-low)/2;

        int smallest=blackbox(matrix,mid,n,m);
        if(smallest<=req) low=mid+1;
        else high=mid-1;
    }
    return low;
}
