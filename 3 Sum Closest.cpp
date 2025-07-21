class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int diff=INT_MAX;
        int ans=0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=n-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(target-sum)<diff){
                    diff=abs(target-sum);
                    ans=sum;
                }
                if(sum<target)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};
