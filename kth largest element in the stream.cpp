class KthLargest {
public:
    int num;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        num=k;
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>num) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>num) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
