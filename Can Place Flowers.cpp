class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s=flowerbed.size();
        int cnt=0;

        for(int i=0;i<s;i++){
            if(flowerbed[i]==0){
                bool f1=(i==0) || (flowerbed[i-1]==0);
                bool f2=(i==s-1) || (flowerbed[i+1]==0);

                if(f1 && f2){
                    flowerbed[i]=1;
                    cnt++;
                    if(cnt>=n) return 1;
                }
            }
        }
        return cnt>=n;
    }
};
