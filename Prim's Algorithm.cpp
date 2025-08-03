class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        int sum=0;
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        
        vector<bool>vis(V,0);
        
        pq.push({0,0});
        
        while(!pq.empty()){
            int edgw=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(vis[node]) continue;
            
            vis[node]=1;
            sum+=edgw;
            
            for(auto &[neighbour,weight]:adj[node]){
                if(!vis[neighbour]){
                    pq.push({weight,neighbour});
                }
            }
        }
        
        return sum;
    }
};
