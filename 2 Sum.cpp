class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int>mpp;

        for(int i=0;i<n;i++){
            int other=target-nums[i];
            if(mpp.count(other)){
                return {i,mpp[other]};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};
