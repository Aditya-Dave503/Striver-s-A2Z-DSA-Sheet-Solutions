class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<long long,int>mpp;
        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            if(mpp.find(nums[i])!=mpp.end()){
                if(i-mpp[nums[i]]<=k) return 1;
            }

            mpp[nums[i]]=i;
        }
        return false;
    }
};
