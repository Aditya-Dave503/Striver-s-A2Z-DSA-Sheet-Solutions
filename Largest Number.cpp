class Solution {
public:
static bool comp(int &a, int &b){
    string s1=to_string(a);
    string s2=to_string(b);

    return s1+s2>s2+s1;
}

    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        string ans="";

        sort(nums.begin(),nums.end(),comp);

        for(auto it:nums){
            ans+=to_string(it);
        }

        bool f=0;

        for(auto it:ans){
            if(it!='0'){
                f=1;
                break;
            } 
        }
        return (f==0)?to_string(0):ans;
    }
};
