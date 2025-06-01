class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();

        map<int,int>mpp;
        vector<int>vec;

        for(auto it:nums) mpp[it]++;

        priority_queue<pair<int,int>>pq;

        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        while(k--){
            auto [f,num]=pq.top();
            vec.push_back(num);
            pq.pop();
        }
        return vec;
    }
};
