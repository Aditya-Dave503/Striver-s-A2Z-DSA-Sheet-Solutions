class Solution {
public:
    char findTheDifference(string s, string t) {
        char xori=0;

        for(char c:s) xori^=c;
        for(char c:t) xori^=c;

        return xori;
    }
};
