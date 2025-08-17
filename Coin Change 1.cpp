class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<int>ans(amount+1,1e9);
        ans[0]=0;

        for(auto coin:coins){
            for(int j=coin;j<amount+1;j+=1){
                ans[j]=min(ans[j],ans[j-coin]+1);
            }
        }

        return ans[amount]==1e9?-1:ans[amount];
    }
};
