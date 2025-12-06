class Solution {
    private:
    int lcs(string str1,string str2){
        int n=str1.size();
        int m=str2.size();

        vector<int>curr(m+1,0),prev(m+1,0);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }

        return prev[m];
    }

    public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        return n+m-2*lcs(word1,word2);
    }
};
