class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size();
        set<pair<int,int>>st;
        priority_queue<pair<long long,pair<int,int>>>pq;
        vector<int>ans;
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        pq.push({a[n-1]+b[n-1],{n-1,n-1}});
        st.insert({n-1,n-1});
        
        while(k--){
            auto it=pq.top();
            pq.pop();
            
            int i=it.second.first;
            int j=it.second.second;
            
            ans.push_back(it.first);
            
            if(i-1>=0 && st.find({i-1,j})==st.end()){
                st.insert({i-1,j});
                pq.push({a[i-1]+b[j],{i-1,j}});
            }
            if(j-1>=0 && st.find({i,j-1})==st.end()){
                st.insert({i,j-1});
                pq.push({a[i]+b[j-1],{i,j-1}});
            }
        }
        
        return ans;
    }
};
