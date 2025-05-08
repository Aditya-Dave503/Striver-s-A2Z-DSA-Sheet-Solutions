class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);

        int pos=0,neg=1;

        for(auto it:nums){
            if(it>0){
                ans[pos]=it;
                pos+=2;
            }
            else{
                ans[neg]=it;
                neg+=2;
            }
        }
        return ans;
    }
};
