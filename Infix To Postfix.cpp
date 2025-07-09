#include<bits/stdc++.h>
int priority(char c){
	if(c == '^') return 3;
	if(c == '*' || c == '/') return 2;
	if(c == '+' || c == '-') return 1;
	return -1;
}





string infixToPostfix(string exp){
	int n = exp.size(), i = 0;
	stack<char>st;
	string ans = "";

	while(i<n){
		if((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))
		ans += exp[i];
		else if(exp[i] == '(') st.push(exp[i]);
		else if(exp[i] == ')'){

			while(!st.empty() && st.top() != '('){
				ans += st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			int temp=priority(exp[i]);
			while(!st.empty() && temp <= priority(st.top())){
				ans += st.top();
				st.pop();
			}
			st.push(exp[i]);
		}
		i++;
	}

	while(!st.empty()){
		ans += st.top();
		st.pop();
	}
	return ans;
}
