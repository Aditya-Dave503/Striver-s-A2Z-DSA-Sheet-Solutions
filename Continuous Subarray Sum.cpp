class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<long long int,int>mpp;
        long long int sum=0;
        mpp[0]=-1;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            long long int need=sum%k;
            if(mpp.find(need)!=mpp.end()){
                if(i-mpp[need]>=2) return 1;
            }
            else mpp[need]=i;
        }
        return false;
    }
};
