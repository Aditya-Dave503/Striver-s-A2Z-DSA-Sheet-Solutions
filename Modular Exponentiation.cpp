class Solution {
public:
    double myPow(double x, long long int n) {
        if(x==0) return 0;
        double ans=1;
        long long int m=n;
        n=abs(n);

        while(n>0){
            if(n&1){
                ans=ans*x;
                n-=1;
            }
            else{
                n/=2;
                x*=x;
            }
        }
        if(m<0) ans=1.0/ans;
        return ans;
    }
};
