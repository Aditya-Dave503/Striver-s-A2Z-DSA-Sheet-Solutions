class Solution {
    private:
    bool dfs(int node,int col,vector<vector<int>>& graph,vector<int>&colour){
        colour[node]=col;

        for(auto it:graph[node]){
            if(colour[it]==-1){
                if(!dfs(it,1-col,graph,colour)) return 0;
            }
            else if(colour[it]==col) return 0;
        }
        return 1;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>colour(n,-1);

        for(int i=0;i<n;i++){
            if(colour[i]==-1){
                if(dfs(i,0,graph,colour)==false) return false;
            }
        }

        return true;
    }
};
