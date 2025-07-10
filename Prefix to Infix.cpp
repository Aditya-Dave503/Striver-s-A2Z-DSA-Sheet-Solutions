string prefixToInfixConversion(string &s){
	int n=s.size();
	int i=n-1;
	stack<string>st;

	while(i>=0){
		if(s[i]>='a' && s[i]<='z') st.push(string(1,s[i]));
		else{
			string t1=st.top();
			st.pop();
			string t2=st.top();
			st.pop();
			string temp='('+t1+s[i]+t2+')';
			st.push(temp);
		}
		i--;
	}
	return st.top();
}
