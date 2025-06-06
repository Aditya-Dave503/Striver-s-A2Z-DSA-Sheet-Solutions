class Solution {
public:

bool f(int n,int k, vector<int>&arr){
    vector<bool>prev(k+1,0), curr(k+1,0);

    prev[0] = curr[0] = 1;

    if(arr[0]<=k)
    prev[arr[0]] = true;

    for(int ind=1;ind<n;ind++){
        for(int j=1;j<=k;j++){
            bool nottake = prev[j];

            bool take=0;
            if(j>=arr[ind]){
                take = prev[j-arr[ind]];
            }

             curr[j]=(take | nottake);
        }
        prev=curr;
    }

    return prev[k];
}

    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        long long int totSum=0;

        for(auto it:arr){
            totSum+=it;
        }

        if(totSum%2) return false;
        int target=totSum/2;

        return f(n,target,arr);
    }
};
