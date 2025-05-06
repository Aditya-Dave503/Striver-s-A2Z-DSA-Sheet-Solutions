class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                count++;
            }
        }

        if(nums[n-1]>nums[0])
        count+=1;

        return count<=1;

    }
};
