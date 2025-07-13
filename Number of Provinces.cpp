class Solution {
public:

    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>&vis){
        vis[node]=1;
        for(int j=0;j<isConnected.size();j++){
            if(!vis[j] && isConnected[node][j]==1){
                dfs(j,isConnected,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        // vector<int>adjls[v];

        // for(int i=0;i<v;i++){
        //     for(int j=0;j<v;j++){
        //         if(isConnected[i][j] && i!=j){
        //             adjls[i].push_back(j);
        //             adjls[j].push_back(i);
        //         }
        //     }
        // }
        vector<bool>vis(v,0);
        int cnt=0;

        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                cnt++;
            }
        }
        return cnt;
    }
};
