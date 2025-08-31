class Solution {
public:
    // int helper(int ind, int target, vector<int>&nums, vector<vector<int>>&dp){
    //     if(ind==0){
    //         if(nums[0]==0 && target==0) return 2;
    //         if(target==0 || target==nums[0]) return 1;
    //         return 0;
    //     }

    //     if(dp[ind][target]!=-1) return dp[ind][target];

    //     int nottake=helper(ind-1,target,nums,dp);
    //     int take=0;
    //     if(nums[ind]<=target) take=helper(ind-1,target-nums[ind],nums,dp);

    //     return dp[ind][target]=nottake+take;
    // }


    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        long long int sum=0;
        for(auto it:nums) sum+=it;
        long long int newtar=(sum-target)/2;

        if(sum-target<0 || (sum-target)%2) return 0;
        vector<int>prev(newtar+1,0),curr(newtar+1,0);

        if(nums[0]==0) prev[0]=2;
        else prev[0]=1;

        if(nums[0]!=0 && nums[0]<=newtar) prev[nums[0]]=1;

        for(int i=1;i<n;i++){
            for(int sum=0;sum<=newtar;sum++){
                int nottake=prev[sum];
                int take=0;
                if(nums[i]<=sum) take=prev[sum-nums[i]];
                curr[sum]=take+nottake;
            }
            prev=curr;
        }
        return prev[newtar];
    }
};
