class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n=nums.size();
        long long int ans=0;
        sort(nums.begin(),nums.end());
        int k=n/3;
        int i=n-2;

        while(k>0){
            ans+=nums[i];
            i-=2;
            k--;
        }
        return ans;
    }
};
