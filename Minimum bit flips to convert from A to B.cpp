class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        int cnt=0;

        while(ans>0){
            int rem=ans%2;
            if(rem==1) cnt+=1;
            ans/=2;
        }
        return cnt;
    }
};
