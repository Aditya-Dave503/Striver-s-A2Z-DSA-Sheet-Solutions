class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,n=s.length(),ans=0;
        vector<int>hash(256,-1);

        while(r<n){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            ans=max(ans,r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return ans;
    }
};
