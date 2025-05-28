class Solution {
public:
long long int power(long long n,long long int r){
    if(r==0) return 1;

    if(r==1) return (n%1000000007);

    long long int ans=1;
    long long int know=power(n,r/2)%1000000007;
    if(r%2) ans=(ans*n)%1000000007;

    return (ans*((know*know)%1000000007))%1000000007;
}
    int countGoodNumbers(long long n) {
        long long int combo=power(20,n/2)%1000000007;
        if(n%2) combo=(combo*5)%1000000007;
        return combo;
    }
};
