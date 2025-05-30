class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),j=1,cnt=0;
        vector<int>prefix(n+1,0);

        for(auto it:nums){
            prefix[j]=prefix[j-1]+it;
            j++;
        }
        unordered_map<int,int>mpp;

        for(int i=1;i<n+1;i++){
            int rem=prefix[i]-k;

            if(prefix[i]==k) cnt++;
            if(mpp.find(rem)!=mpp.end()){
                cnt+=mpp[prefix[i]-k];
            }
            mpp[prefix[i]]++;
        }
        return cnt;
    }
};
