class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans;
        set<int>st;
        map<int,int>mpp;

        for(auto it:arr){
            st.insert(it);
        }
        int i=1;
        for(auto it:st){
            mpp[it]=i;
            i++;
        }

        for(auto it:arr){
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};
