class Solution {
public:

    int f(vector<int>&nums,int k){
        if(k<0) return 0;

        int n=nums.size();
        int l=0,r=0,ans=0,cnt=0;

        while(r<n){
            if(nums[r]&1) cnt++;

            while(cnt>k){
                if(nums[l]&1) cnt--;
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int t1=f(nums,k);
        int t2=f(nums,k-1);
        return t1-t2;
    }
};
