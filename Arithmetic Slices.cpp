class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int count=0,ans=0;

        if(n<3) return 0;

        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                count++;
                ans+=count;
            }
            else{
                count=0;
            }
        }
        return ans;
    }
};
