class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n=arr.size(),cost=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        while(pq.size()>1){
            int len1=pq.top();
            pq.pop();
            int len2=pq.top();
            pq.pop();
            cost+=len1+len2;
            
            pq.push(len1+len2);
        }
        return cost;
    }
};
