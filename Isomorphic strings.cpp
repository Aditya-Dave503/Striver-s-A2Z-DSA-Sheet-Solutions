class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int hashs[256]={0},hasht[256]={0};

        for(int i=0;i<n;i++){
            if(hashs[s[i]]!=hasht[t[i]]) return false;

            hashs[s[i]]=i+1;
            hasht[t[i]]=i+1;
        }
        return true;
    }
};
