// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto it:edges){
            int u=it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<int>dis(V,1e9);
        dis[src]=0;
        
        pq.push({0,src});
        
        while(!pq.empty()){
            int edgeweight=pq.top().first;
            int adjacentnode=pq.top().second;
            pq.pop();
            
            for(auto &[neighbour,weight]:adj[adjacentnode]){
                if(edgeweight+weight<dis[neighbour]){
                    dis[neighbour]=edgeweight+weight;
                    pq.push({edgeweight+weight,neighbour});
                }
            }
        }
        
        return dis;
    }
};
