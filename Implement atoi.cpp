class Solution {
  public:
    int myAtoi(char *s) {
        if(s == nullptr || s[0] == '\0') return -1;

        int i = 0, sign = 1;
        long long ans = 0;

        if(s[i] == '-') {
            sign = -1;
            i++;
        } else if(s[i] == '+') {
            i++;
        }

        if(s[i] == '\0') return 0;

        for(; s[i] != '\0'; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + (s[i] - '0');

                if(sign == 1 && ans > INT_MAX) return INT_MAX;
                if(sign == -1 && -ans < INT_MIN) return INT_MIN;
            }else{
                if(sign==-1) return -ans;
                return ans;
            }
        }

        return sign * ans;
    }
};
