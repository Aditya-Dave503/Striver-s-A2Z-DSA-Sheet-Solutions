int countDigits(int n){
	long long int t=n;
	int ans=0;

	while(n>0){
		int rem=n%10;
		if(rem!=0 && t%rem==0) ans+=1;
		n/=10;
	}	
	return ans;
}
