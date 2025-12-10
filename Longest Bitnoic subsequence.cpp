class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int>dp1(n,1),dp2(n,1);
        
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev] && 1+dp1[prev]>dp1[i]){
                    dp1[i]=1+dp1[prev];
                }
            }
        }
        
        for(int i=n-1;i>=1;i--){
            for(int prev=n-1;prev>i;prev--){
                if(nums[i]>nums[prev] && 1+dp2[prev]>dp2[i]){
                    dp2[i]=1+dp2[prev];
                }
            }
        }
        
        int maxi=0;
        for(int i=0;i<n;i++){
            if(dp1[i]>1 && dp2[i]>1)
                maxi=max(maxi,dp1[i]+dp2[i]-1);
        }
        return maxi;
    }
};
