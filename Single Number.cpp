class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xori=nums[0];
        int n=nums.size();

        for(int i=1;i<n;i++){
            xori=xori^nums[i];
        }
        return xori;
        
    }
};
