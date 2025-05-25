class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int j=0;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                int ele=pq.top();
                pq.pop();
                arr[j]=ele;
                j++;
            }
        }
        
        while(j<arr.size()){
            int ele=pq.top();
            pq.pop();
            arr[j]=ele;
            j++;
        }
    }
};
