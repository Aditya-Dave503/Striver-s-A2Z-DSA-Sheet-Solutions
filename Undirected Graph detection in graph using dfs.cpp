class Solution {
    private:
    bool detect(int node, int parent, vector<bool>&vis, vector<vector<int>>&adj){
        vis[node]=1;
        
        for(int adjacentnode:adj[node]){
            if(!vis[adjacentnode]){
                if(detect(adjacentnode,node,vis,adj)) return 1;
            }
            else if(adjacentnode!=parent) return 1;
        }
        return 0;
    }
 
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<bool>vis(V,0);
        vector<vector<int>>adj(V);
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,-1,vis,adj)) return 1;
            }
        }
        return 0;
    }
};
