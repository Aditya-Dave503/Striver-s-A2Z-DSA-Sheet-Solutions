class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=0;
        vector<int>ans;

        for(int i=n-1;i>=0;i--){
            int temp=0;
            if(i==n-1) temp=digits[i]+1+carry;
            else temp=digits[i]+carry;
            digits[i]=temp%10;
            if(temp>=10) carry=temp/10;
            else carry=0;
        }

        if(carry>0) ans.push_back(carry);

        for(int i=0;i<n;i++) ans.push_back(digits[i]);
        return ans;
    }
};
