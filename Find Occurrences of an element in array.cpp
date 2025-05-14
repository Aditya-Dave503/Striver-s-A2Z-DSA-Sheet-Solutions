class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n=nums.size();
        vector<int>temp,ans;
        for(int i=0;i<n;i++){
            if(nums[i]==x) temp.push_back(i);
        }

        for(int i=0;i<queries.size();i++){
            if(queries[i]>temp.size()) ans.push_back(-1);
            else ans.push_back(temp[queries[i]-1]);
        }
        return ans;
    }
};
