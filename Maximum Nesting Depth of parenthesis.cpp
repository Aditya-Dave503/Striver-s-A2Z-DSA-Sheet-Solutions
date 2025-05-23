class Solution {
public:
    int maxDepth(string s) {
        int res=0,cnt=0;

        for(auto it:s){
            if(it=='('){
                cnt+=1;
            }
            else if(it==')') cnt-=1;
            res=max(res,cnt);
        }
        return res;
    }
};
