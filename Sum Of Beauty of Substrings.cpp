class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++){
            vector<int>a(26,0);
            for(int j=i;j<n;j++){
                a[s[j]-'a']+=1;
                int maxi=INT_MIN;
                int mini=INT_MAX;

                for(int k=0;k<26;k++){
                    maxi=max(maxi,a[k]);
                    if(a[k]>0) mini=min(mini,a[k]);
                }
                ans+=maxi-mini;
            }
        }

        return ans;
    }
};
