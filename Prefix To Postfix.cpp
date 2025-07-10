#include<bits/stdc++.h>
string preToPost(string s) {
    int n=s.size();
    int i=0;
    stack<string>st;

    for(int i=n-1;i>=0;i--){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        st.push(string(1,s[i]));
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string temp=t1+t2+s[i];
            st.push(temp);
        }
    }
    return st.top();
}
