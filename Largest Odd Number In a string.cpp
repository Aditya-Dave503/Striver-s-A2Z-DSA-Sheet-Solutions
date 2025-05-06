class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        string ans="";
        bool flag=0;

        for(int i=n-1;i>=0;i--){
            int digit=num[i]-'0';
            if( digit%2){
                flag=1;
                ans+=num[i];
            }
            else if(flag==1){
                ans+=num[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
