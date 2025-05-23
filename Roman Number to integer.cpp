class Solution {
public:
    int cal(char a){
        if(a=='I') return 1;
        if(a=='V') return 5;
        if(a=='X') return 10;
        if(a=='L') return 50;
        if(a=='C') return 100;
        if(a=='D') return 500;
        return 1000;
    }
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(i<s.size()-1){
                int v1=cal(s[i]);
                int v2=cal(s[i+1]);
                if(v1<v2)ans-=v1;
                else ans+=v1;
            }
            else ans+=cal(s[i]);
        }
        return ans;
    }
};
