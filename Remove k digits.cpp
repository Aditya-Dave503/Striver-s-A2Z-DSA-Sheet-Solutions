class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k-=1;
            }
            st.push(num[i]);
        }

        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        while(!ans.empty() && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.empty()) return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
