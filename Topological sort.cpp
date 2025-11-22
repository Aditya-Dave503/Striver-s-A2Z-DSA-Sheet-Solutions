class Solution {
    private:
    void dfs(int node, vector<bool>&vis,vector<vector<int>>&edges,
    stack<int>&st){
        vis[node]=1;
        
        for(auto it:edges[node]){
            if(!vis[it]){
                dfs(it,vis,edges,st);
            }
        }
        st.push(node);
    }
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<bool>vis(V,0);
        stack<int>st;
        vector<vector<int>>adj(V);
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
