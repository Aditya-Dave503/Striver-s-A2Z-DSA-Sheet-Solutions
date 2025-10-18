class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>after(2,vector<int>(3,0)),curr(2,vector<int>(3,0));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        curr[buy][cap]=max(-prices[ind]+after[0][cap],0+after[1][cap]);
                    }
                    else{
                        curr[buy][cap]=max(prices[ind]+after[1][cap-1],0+after[0][cap]);
                    }
                }
            }
            after=curr;
        }
        return after[1][2];
    }
};
