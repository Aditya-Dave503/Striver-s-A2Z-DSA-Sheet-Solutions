class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int lastseen[3]={-1,-1,-1};
        int ans=0;

        for(int i=0;i<n;i++){
            lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                ans+=(1+(*min_element(lastseen,lastseen+3)));
            }
        }
        return ans;
    }
};
