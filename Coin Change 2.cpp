class Solution {
public:
    int change(int amount, vector<int>& coins) {
        using u128=unsigned __int128;
        int n=coins.size();
        vector<u128>prev(amount+1,0),curr(amount+1,0);

        for(int i=0;i<=amount;i++) prev[i]=(i%coins[0]==0);

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                u128 nottake=prev[j];
                u128 take=0;

                if(coins[i]<=j) take=curr[j-coins[i]];
                curr[j]=(take+nottake);
            }
            prev=curr;
        }
        return (int)prev[amount];
    }
};
