int minSubsetSumDifference(vector<int>& arr, int n)
{
        long long int sum = 0;

        for(int i = 0; i < n; i++) sum+=arr[i];

        int k = sum;
        vector<vector<bool>>dp(n, vector<bool>(k+1,false)) ;

        for(int i=0;i<n;i++) dp[i][0] = 1;

        if(arr[0]<=sum) dp[0][arr[0]]=true; 

        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool notake=dp[i-1][target];
                bool take=0;

                if(arr[i] <= target){
                    take= dp[i-1][target-arr[i]];
                }
                dp[i][target]=take|| notake;
            }
        }

        long long int mini=1e9;

        for(int s1=0;s1<=sum/2;s1++){
            if(dp[n-1][s1]==true){
                long long int s2=sum-s1;
                mini= min(mini,abs(s1-s2));
            }
        }
        return mini;
}
