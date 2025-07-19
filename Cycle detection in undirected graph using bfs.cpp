class Solution {
    private:
    
        bool detect(int src, vector<vector<int>>& edges, vector<bool>&vis){
            vis[src]=1;
            queue<pair<int,int>>q;
            q.push({src,-1});
            
            while(!q.empty()){
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                
                for(auto adjacentnode:edges[node]){
                    if(!vis[adjacentnode]){
                        vis[adjacentnode]=1;
                        q.push({adjacentnode,node});
                    }
                    else if(parent!=adjacentnode) return 1;
                }
            }
            return 0;
        }
        
        
  public:
    bool isCycle(int v, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(v);
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(v,0);
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)) return 1;
            }
        }
        return 0;
    }
};
