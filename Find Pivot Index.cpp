class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>psum(n,0);
        int total=0;

        for(int i=n-1;i>=0;i--) total+=nums[i];

        int sum=0;

        for(int i=0;i<n;i++){
            if(sum==total-sum-nums[i]) return i;
            sum+=nums[i];
        }
        return -1;
    }
};
