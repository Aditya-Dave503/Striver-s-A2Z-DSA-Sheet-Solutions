class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;
        sort(nums.begin(),nums.end());

        for(int mask=0;mask<(1<<n);mask++){
            vector<int>temp;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)) temp.push_back(nums[i]);
            }
            st.insert(temp);
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};
