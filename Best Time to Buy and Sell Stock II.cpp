class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int mini=prices.at(0);
        int sum=0;

        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1]){
                sum+=prices[i]-prices[i-1];
            }
        }
        return sum;
        
    }
};
