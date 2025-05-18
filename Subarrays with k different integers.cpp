class Solution {
public:
int f(vector<int>& nums, int k){
    int l=0,r=0,n=nums.size();
    int cnt=0;
    unordered_map<int,int>mpp;

    while(r<n){
        mpp[nums[r]]++;

        while(mpp.size()>k){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0) mpp.erase(nums[l]);
            l++;
        }
        cnt+=r-l+1;
        r++;
    }
    return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};
