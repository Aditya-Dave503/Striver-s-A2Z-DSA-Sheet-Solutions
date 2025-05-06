class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size();

        int mid=start+(end-start)/2;
        if(target>nums[end-1])
        return end;

        while(start <= end)
        {
            mid=start+(end-start)/2;
            if(nums.at(mid)==target)
            return mid;
            else if(nums.at(mid)<target)
            start=mid+1;
            else
            end=mid-1;

        }

       return start;
    }
};
