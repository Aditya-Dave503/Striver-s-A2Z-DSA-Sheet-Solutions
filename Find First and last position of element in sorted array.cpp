class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans(2,-1);
        if(n==0) return ans;

        int start=0,end=n-1,answ=-1;

        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                answ=mid;
                end=mid-1;
            }
            else if(nums[mid]>target) end=mid-1;
            else start=mid+1;
        }
        ans[0]=answ;

        start=0,end=n-1; answ=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                answ=mid;
                start=mid+1;
            }
            else if(nums[mid]>target) end=mid-1;
            else start=mid+1;
        }
        ans[1]=answ;
        return ans;
    }
};
