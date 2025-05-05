class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0,temp=0,ans=0;

        while(r<n){
            temp+=(nums[r]==0);
            if(temp>k){
                temp-=(nums[l]==0);
                l++;

            } 
            if(temp<=k) ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
