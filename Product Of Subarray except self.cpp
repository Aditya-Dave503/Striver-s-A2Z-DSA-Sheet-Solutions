class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int start=1;
        vector<int>ans(n,0);

        for(int i=0;i<n;i++){
            ans[i]=start;
            start*=nums[i];
        }

        start=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=start;
            start*=nums[i];
        }
        return ans;
    }
};
