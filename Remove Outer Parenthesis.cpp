class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string ans="";
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]==')') cnt--;
            if(cnt!=0) ans+=s[i];
            if(s[i]=='(') cnt++;
        }
        return ans;
    }
};
