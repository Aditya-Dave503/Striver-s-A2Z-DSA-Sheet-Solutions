class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
       int n=obs[0].size();
       int m=obs.size();
       vector<long long int>dp(n,0);
       dp[0]=1;

       for(int i=0;i<m;i++){
        vector<long long int>temp(n,0);
        for(int j=0;j<n;j++){
            if(obs[i][j]==1){
                temp[j]=0;
            }
            else if(i==0 && j==0) temp[j]=1;
            else{
                int up=0,left=0;
                if(i>0) up=dp[j];
                if(j>0) left=temp[j-1];
                temp[j]=up+left;
            }
        }
        dp=temp;
       }
       return dp[n-1];
    }
};
