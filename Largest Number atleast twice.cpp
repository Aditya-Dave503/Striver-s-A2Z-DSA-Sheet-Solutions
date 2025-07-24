class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int secondmaxi=-1,maxi=-1,ind=-1;

        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                secondmaxi=maxi;
                maxi=nums[i];
                ind=i;
            }
            else if(nums[i]>secondmaxi) secondmaxi=nums[i];
        }

        if(maxi>=2*secondmaxi) return ind;
        return -1;
    }
};
