int setBits(int n){
    // Write your code here.
    int t=n;
    int cnt=0,ans=-1;

    while(t>0){
        int rem=t%2;
        cnt+=1;
        if(rem==0) {
            ans=cnt;
            break;
        }
        t=t/2;
    }
    if(ans==-1) return n;
    n=n^(1<<(ans-1));
    return n;
}
