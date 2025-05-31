class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        long long int xori=0;

        for(auto it:nums) xori=xori^it;

        long long int temp=xori & ~(xori-1);            // find rightmost set bit
        long long int num1=0,num2=0;                    // bucket 1 and bucket 2

        for(auto it:nums){
            if((temp& it)!=0) num1^=it;
            else num2^=it;
        }
        ans.push_back(num1);
        ans.push_back(num2);
        return ans;
    }
};
