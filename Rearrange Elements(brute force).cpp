class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos,neg,ans;

        for(auto it:nums){
            if(it>0) pos.push_back(it);
            else neg.push_back(it);
        }
        bool fg=0;
        int j=0,k=0;
        for(int i=0;i<n;i++){
            if(!fg){
                ans.push_back(pos[j]);
                fg=1;
                j++;
            }
            else{
                ans.push_back(neg[k]);
                fg=0;
                k++;
            }
        }
        return ans;
    }
};
