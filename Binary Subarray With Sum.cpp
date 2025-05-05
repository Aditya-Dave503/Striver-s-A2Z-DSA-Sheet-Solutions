class Solution {
public:
    int func(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int n=nums.size();
        int l=0,r=0,sum=0,count=0;

        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int t1=func(nums,goal);
        int t2=func(nums,goal-1);
        return t1-t2;
    }
};
