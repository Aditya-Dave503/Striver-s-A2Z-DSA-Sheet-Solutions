class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long int n=nums.size();
        long int arrsum=(n*(n+1))/2;
        long int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        return arrsum-sum;
        
    }
};
