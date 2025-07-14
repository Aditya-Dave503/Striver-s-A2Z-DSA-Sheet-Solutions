class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int median=nums[n/2];

        long long ans=0;

        for(int i=0;i<n;i++){
            ans+=abs(nums[i]-median);
        }
        return ans;
    }
};
