class Solution {
    private:
        vector<int>generaterow(int row){
            long long int ans=1;
            vector<int>ansrow;
            ansrow.push_back(ans);

            for(int col = 1; col < row; col++){
                ans*=(row-col);
                ans/=col;
                ansrow.push_back(ans);
            }
            return ansrow;
        }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int i = 1;i <= numRows; i++){
            ans.push_back(generaterow(i));
        }
        return ans;
    }
};
