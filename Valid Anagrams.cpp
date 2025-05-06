class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hash1(27,0),hash2(27,0);

        for(int i=0;i<s.size();i++)
        hash1[s[i]-'a']+=1;

        for(int i=0;i<t.size();i++)
        hash2[t[i]-'a']+=1;

        if(hash1==hash2)
        return true;
        return false;
    }
};
