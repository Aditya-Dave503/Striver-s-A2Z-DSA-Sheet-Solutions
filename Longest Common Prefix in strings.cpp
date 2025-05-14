class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        sort(strs.begin(),strs.end());
        string st=strs[0];
        string end=strs[n-1];        

        for(int i=0;i<st.size();i++){
            if(st[i]!=end[i]) break;
            ans+=st[i];
        }
        return ans;
    }
};
