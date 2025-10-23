string minWindow(string s, string t)
{
	int n=s.size();
	string ans="";
	int l=0,r=0,r2=0,len=INT_MAX;

	while(r<n){
		if(s[r]==t[r2]) r2++;

		if(r2==t.size()){
			l=r;
			r2--;
			while(l>=0 && r2>=0){
				if(s[l]==t[r2]) r2--;
				l--;
			}
			l++;
			if(r-l+1<len){
				len=r-l+1;
				ans=s.substr(l,r-l+1);
			}
			r2=0;
			r=l+1;
		}
		r++;
	}
	return ans;
}
