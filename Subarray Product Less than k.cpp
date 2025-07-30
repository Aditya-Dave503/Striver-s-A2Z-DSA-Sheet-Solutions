class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        int n=nums.size();
        int l=0,r=0;
        long long int multi=1,ans=0;

        while(r<n){
            multi*=nums[r];

            while(l<=r && multi>=k){
                multi/=nums[l];
                l++;
            }
            if(multi<k) ans+=r-l+1;
            r++;
        }
        return ans;
    }
};
