class Solution {
    // private:
    // int f(int i,int j, string &s,string &p,vector<vector<int>>&dp){
    //     if(i<0 && j<0) return 1;
    //     if(j<0 && i>=0) return 0;
    //     if(i<0 && j>=0){
    //         for(int k=0;k<=j;k++){
    //             if(p[k]!='*') return 0;
    //         }
    //         return 1;
    //     }

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(s[i]==p[j] || p[j]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);
    //     if(p[j]=='*') return dp[i][j]=f(i-1,j,s,p,dp) | f(i,j-1,s,p,dp);
    //     return dp[i][j]=0;
    // }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<bool>curr(m+1,0),prev(m+1,0);
        prev[0]=1;

        for(int i=1;i<=m;i++) prev[i]=0;

        for(int i=1;i<=m;i++){
            prev[i]=(prev[i-1] && p[i-1]=='*');
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') curr[j]=prev[j-1];
                else if(p[j-1]=='*') curr[j]=prev[j] || curr[j-1];
                else curr[j]=0;
            }
            prev=curr;
        }

        if(n==0) return prev[m];
        return curr[m];
    }
};
