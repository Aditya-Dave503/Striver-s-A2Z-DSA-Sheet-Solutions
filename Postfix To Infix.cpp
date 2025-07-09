#include<bits/stdc++.h>
string postToInfix(string postfix) {
    stack<string>st;
    int i=0;
    int n=postfix.size();

    while(i<n){
        if((postfix[i]>='A' && postfix[i]<='Z') || (postfix[i]>='a' && postfix[i]<='z')
        || (postfix[i]>='0' && postfix[i]<='9')) st.push(string(1,postfix[i]));
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string temp='('+t2+postfix[i] + t1+')';
            st.push(temp);
        }
        i++;
    }
    return st.top();
}
