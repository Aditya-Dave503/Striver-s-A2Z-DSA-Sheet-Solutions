class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        unordered_map<string,int>mpp;
        vector<string>ans;
        if(n<10) return ans;

        for(int i=0;i<=n-10;i++){
            string a=s.substr(i,10);
            mpp[a]++;
        }

        for(auto it:mpp){
            if(it.second>=2) ans.push_back(it.first);
        }
        return ans;
    }
};
