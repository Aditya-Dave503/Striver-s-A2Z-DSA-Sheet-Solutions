class Solution {
    private:
    bool dfs(int node,vector<vector<int>>& a,vector<bool>&vis,vector<int>&pathvis,vector<int>&ans){
        vis[node]=1;
        pathvis[node]=1;

        for(auto it:a[node]){
            if(!vis[it]){
                if(dfs(it,a,vis,pathvis,ans)) return 1;
            }
            else if(pathvis[it]==1) return true;
        }

        pathvis[node]=0;
        ans.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<bool>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        vector<int>ans;

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis,ans)) return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
