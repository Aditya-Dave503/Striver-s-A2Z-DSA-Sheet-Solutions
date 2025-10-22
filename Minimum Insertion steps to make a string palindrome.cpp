class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(text1[ind1-1]==text2[ind2-1]) dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                else
                    dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return dp[n][m];
    }

    int longestPalindromeSubseq(string &s) {
        string t=s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
    }
    int minInsertions(string s) {
        int temp=longestPalindromeSubseq(s);
        return s.size()-temp;
    }
};
