class Solution {
public:
    int mySqrt(int x) {
        int l=0,h=x,ans=-1;

        while(l<=h){
            int m=l+(h-l)/2;
            if((long long)m*m<=x){
                ans=m;
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
    }
};
