class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<long long int>pq;

        for(auto it:nums) pq.push(it);
        long long int ans=0;

        for(int i=0;i<k;i++){
            ans=pq.top();
            pq.pop();
        }
        return ans;
    }
};
